#include "MPU9250.h"

void MPU9250_init(void){
	I2C_init();
}


int MPU9250_WhoAmI (uint8_t * WhoAmI){
	return I2C_readRegisters(ACC_I2C_ADDRES,WHO_AM_I_MPU9250,WhoAmI,1);
}


int MPU9250_get_acc(int * pX ,int * pY, int * pZ){
	uint8_t accTemp[6] = {0};
	
	I2C_readRegisters(ACC_I2C_ADDRES,ACCEL_XOUT_H,accTemp,6);

	*pX = (int)(((accTemp[0]<<8)|accTemp[1])*(ADC2mg));
	*pY = (int)(((accTemp[2]<<8)|accTemp[3])*(ADC2mg));
	*pZ = (int)(((accTemp[4]<<8)|accTemp[5])*(ADC2mg));
	return 0;
}
