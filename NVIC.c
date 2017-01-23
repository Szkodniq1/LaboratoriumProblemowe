#include "NVIC.h"

void initNVIC(NVIC_InitTypeDef* NVIC_InitStructure)
{
	initSynchroInterrupt(NVIC_InitStructure);
	initEncoderAInterrupt(NVIC_InitStructure);
	initEncoderBInterrupt(NVIC_InitStructure);
	initPCUARTInterrupt(NVIC_InitStructure);
	initEncoderUARTInterrupt(NVIC_InitStructure);
	initDroneUARTInterrupt(NVIC_InitStructure);
	enableNVIC();
}

void initSynchroInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStructure->NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure->NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(NVIC_InitStructure);
}

void initEncoderAInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStructure->NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStructure->NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(NVIC_InitStructure);
}

void initEncoderBInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStructure->NVIC_IRQChannel = EXTI2_IRQn;
	NVIC_InitStructure->NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(NVIC_InitStructure);
}

void initPCUARTInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStructure->NVIC_IRQChannel = UART4_IRQn;
	NVIC_InitStructure->NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure->NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(NVIC_InitStructure);
}

void initDroneUARTInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStructure->NVIC_IRQChannel = USART6_IRQn;
	NVIC_InitStructure->NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure->NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(NVIC_InitStructure);
}

void enableNVIC() {
	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_EnableIRQ(UART4_IRQn);
	NVIC_EnableIRQ(USART6_IRQn);
}
