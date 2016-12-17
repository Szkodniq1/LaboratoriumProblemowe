#include "USART.h"

void initUSART(USART_InitTypeDef* USART_InitStructure)
{
	initPCUART(USART_InitStructure);
	initEncoderUSART(USART_InitStructure);
	initDroneUSART(USART_InitStructure);
}

void initPCUART(USART_InitTypeDef* USART_InitStructure) {
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);

	USART_Cmd(UART4, ENABLE);

	USART_InitStructure->USART_BaudRate = UART_BAUDRATE;
	USART_InitStructure->USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure->USART_Parity = USART_Parity_No;
	USART_InitStructure->USART_StopBits = USART_StopBits_1;
	USART_InitStructure->USART_WordLength = USART_WordLength_8b;
	USART_InitStructure->USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(UART4, USART_InitStructure);

	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
}

void initEncoderUSART(USART_InitTypeDef* USART_InitStructure) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	USART_Cmd(USART1, ENABLE);

	USART_InitStructure->USART_BaudRate = UART_BAUDRATE;
	USART_InitStructure->USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure->USART_Parity = USART_Parity_No;
	USART_InitStructure->USART_StopBits = USART_StopBits_1;
	USART_InitStructure->USART_WordLength = USART_WordLength_8b;
	USART_InitStructure->USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART1, USART_InitStructure);

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}

void initDroneUSART(USART_InitTypeDef* USART_InitStructure) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);

	USART_Cmd(USART6, ENABLE);

	USART_InitStructure->USART_BaudRate = UART_BAUDRATE;
	USART_InitStructure->USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure->USART_Parity = USART_Parity_No;
	USART_InitStructure->USART_StopBits = USART_StopBits_1;
	USART_InitStructure->USART_WordLength = USART_WordLength_8b;
	USART_InitStructure->USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART6, USART_InitStructure);

	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);
}

void USART_put(USART_TypeDef* USARTx, volatile char *s){
	while(*s){
		while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);
		USART_SendData(USARTx, *s);
		*s++;
	}
}

void USART_put_float(USART_TypeDef* USARTx, float f){
	char convertedFloat[4];
	sprintf(convertedFloat, "%f", f);
	USART_put(USARTx, convertedFloat);
}

void USART_put_long(USART_TypeDef* USARTx, unsigned long l){
	char convertedLong[4];
	sprintf(convertedLong, "%lu", l);
	USART_put(USARTx, convertedLong);
}

