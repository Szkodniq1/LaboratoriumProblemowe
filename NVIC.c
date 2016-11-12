#include "NVIC.h"

void initNVIC(NVIC_InitTypeDef* NVIC_InitStructure)
{
	initSynchroInterrupt(NVIC_InitStructure);
	initPCUARTInterrupt(NVIC_InitStructure);
	initEncoderUARTInterrupt(NVIC_InitStructure);
	initDroneUARTInterrupt(NVIC_InitStructure);
}

void initSynchroInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStructure->NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure->NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(NVIC_InitStructure);
}

void initPCUARTInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStruct.NVIC_IRQChannel = UART4_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStruct);
}

void initEncoderUARTInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStruct);
}

void initDroneUARTInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStruct.NVIC_IRQChannel = USART6_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStruct);
}
