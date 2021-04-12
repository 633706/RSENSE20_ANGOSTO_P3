#ifndef __MPU9250_H__
#define __MPU9250_H__

#include "MPU9250_registerMap.h"

#include "I2C.h"

#define ADC2mg ((9800.0)/(65535.0))

void MPU9250_init(void);
int MPU9250_WhoAmI (uint8_t * WhoAmI);
int MPU9250_get_acc(int * pX ,int * pY, int * pZ);

#endif //__MPU9250_H__