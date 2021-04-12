#ifndef __I2C_H__
#define __I2C_H__

#include "driver/i2c.h"

#define SCL_PIN (27)
#define SDA_PIN (26)

#define ACK_EN (1)
#define NACK_EN (0)


esp_err_t I2C_init(void);

esp_err_t I2C_writeRegisters(uint8_t address, uint8_t subAddress, uint8_t* data, int size);
esp_err_t I2C_readRegisters(uint8_t address, uint8_t subAddress, uint8_t* data, int size);

#endif // __I2C_H__