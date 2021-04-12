#ifndef __UART_H__
#define __UART_H__
#include <stdio.h>
#include <string.h>

#include "driver/uart.h"


void UART_init ();
void UART_send (const char * txt);
int UART_ReadyToReceive (void);
void UART_Receive(unsigned char * txt, int size);
#endif
