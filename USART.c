#include "USART.h"

void initUSART(USART_InitTypeDef* USART_InitStructure)
{
	initPCUART(USART_InitStructure);
	initEncoderUSART(USART_InitStructure);
	initDroneUSART(USART_InitStructure);
}

void initPCUART(USART_InitTypeDef* USART_InitStructure) {
	USART_InitStructure->USART_BaudRate = 9600;
	USART_InitStructure->USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure->USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure->USART_Parity = USART_Parity_No;
	USART_InitStructure->USART_StopBits = USART_StopBits_1;
	USART_InitStructure->USART_WordLength = USART_WordLength_8b;
	USART_Init(UART4, USART_InitStructure);
	USART_Cmd(UART4, ENABLE);

	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
}

void initEncoderUSART(USART_InitTypeDef* USART_InitStructure) {
	USART_InitStructure->USART_BaudRate = 9600;
	USART_InitStructure->USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure->USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure->USART_Parity = USART_Parity_No;
	USART_InitStructure->USART_StopBits = USART_StopBits_1;
	USART_InitStructure->USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, USART_InitStructure);
	USART_Cmd(USART1, ENABLE);

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}

void initDroneUSART(USART_InitTypeDef* USART_InitStructure) {
	USART_InitStructure->USART_BaudRate = 9600;
	USART_InitStructure->USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure->USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure->USART_Parity = USART_Parity_No;
	USART_InitStructure->USART_StopBits = USART_StopBits_1;
	USART_InitStructure->USART_WordLength = USART_WordLength_8b;
	USART_Init(USART6, USART_InitStructure);
	USART_Cmd(USART6, ENABLE);

	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);
}
