#include "EXTI.h"

void initEXTI(EXTI_InitTypeDef* EXTI_InitStruct)
{
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource0);

	EXTI_InitStruct->EXTI_Line = EXTI_Line0;
	EXTI_InitStruct->EXTI_LineCmd = ENABLE;
	EXTI_InitStruct->EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct->EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(EXTI_InitStruct);
}
