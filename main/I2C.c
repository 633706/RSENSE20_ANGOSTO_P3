#include "I2C.h"

esp_err_t I2C_init(void){
	i2c_config_t conf = {
	.mode = I2C_MODE_MASTER,
	.sda_io_num = SDA_PIN,
	.sda_pullup_en = GPIO_PULLUP_ENABLE,
	.scl_io_num = SCL_PIN,
	.scl_pullup_en = GPIO_PULLUP_ENABLE,
	.master.clk_speed = 100000,
	};
	esp_err_t err = i2c_param_config(I2C_NUM_0,&conf);
	i2c_driver_install(I2C_NUM_0, conf.mode, 0, 0, 0);
	return err;
}


esp_err_t I2C_writeRegisters(uint8_t address, uint8_t subAddress, uint8_t* data, int size){
	i2c_cmd_handle_t cmd = i2c_cmd_link_create();
	i2c_master_start(cmd); //start condition
	i2c_master_write_byte(cmd, (address<<1 | I2C_MASTER_WRITE), ACK_EN); //Write addess (W)
	i2c_master_write_byte(cmd,subAddress,ACK_EN); //Write subaddress
	i2c_master_write(cmd,(data),size,ACK_EN ); //Write data
	i2c_master_stop(cmd); //stop condition
	
	esp_err_t err = i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000);
	i2c_cmd_link_delete(cmd);
	return err;
}


esp_err_t IRAM_ATTR I2C_readRegisters(uint8_t address, uint8_t subAddress, uint8_t* data, int size){
	i2c_cmd_handle_t cmd = i2c_cmd_link_create();

	i2c_master_start(cmd); //start condition
	i2c_master_write_byte(cmd, (address<<1 | I2C_MASTER_WRITE), ACK_EN); //write address (W)
	i2c_master_write_byte(cmd,subAddress,ACK_EN ); //write subaddres

	i2c_master_start(cmd); //start condition
	i2c_master_write_byte(cmd, (address<<1 | I2C_MASTER_READ), ACK_EN); //Write address (R)
	
	if(size>1){
		i2c_master_read(cmd,(data),(size-1),I2C_MASTER_ACK);
	}
	i2c_master_read_byte(cmd,((data+size-1)),I2C_MASTER_NACK); //Read byte (NACK)
	i2c_master_stop(cmd); //stop condition	
	esp_err_t err = i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000);
	i2c_cmd_link_delete(cmd);
	return err;
}