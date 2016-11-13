#ifndef __SERIAL_H
#define __SERIAL_H

#include "stm32f4xx_usart.h"
#include "stm32f4xx_rcc.h"

#define UART_BAUDRATE 9600

void initUSART(USART_InitTypeDef* USART_InitStructure);
void initPCUART(USART_InitTypeDef* USART_InitStructure);
void initEncoderUSART(USART_InitTypeDef* USART_InitStructure);
void initDroneUSART(USART_InitTypeDef* USART_InitStructure);
void USART_put(USART_TypeDef* USARTx, volatile char *s);

#endif
