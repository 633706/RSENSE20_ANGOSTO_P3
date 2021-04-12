#ifndef __MAIN_H__
#define __MAIN_H__
//Librerarías estandar de  C
#include <stdio.h>
#include <string.h>
//drivers propios ESP32

#include "UART.h"
#include "I2C.h"
#include "GPIO.h"
//librerías FREERTOS
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//otras librearías
#include "MPU9250.h"

char msgTx_PC[100]= "Running\r\n";

uint8_t WhoAmI_ = 0;
int accX = 0;
int accY = 0;
int accZ = 0;
char nSamples = 0;

TaskHandle_t LEDHandle;
TaskHandle_t UARTHandle;
TaskHandle_t IMUHandle;

TickType_t LastSample;

#endif /* __MAIN_H__ */
