#ifndef __USART_H
#define __USART_H

#include "stm32f4xx_usart.h"
#include "stm32f4xx_rcc.h"

#define UART_BAUDRATE 9600

#define PC UART4
#define DRONE USART6

void initUSART(USART_InitTypeDef* USART_InitStructure);
void initPCUART(USART_InitTypeDef* USART_InitStructure);
void initDroneUSART(USART_InitTypeDef* USART_InitStructure);
void USART_put_char(USART_TypeDef* USARTx, uint8_t ch);
void USART_put_string(USART_TypeDef* USARTx, volatile char *s);
void USART_put_float(USART_TypeDef* USARTx, float f);
void USART_put_long(USART_TypeDef* USARTx, unsigned long l);

#endif
