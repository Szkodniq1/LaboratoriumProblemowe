#include "EXTI.h"

void initEXTI(EXTI_InitTypeDef* EXTI_InitStruct)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource0);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource1);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource2);

	EXTI_InitStruct->EXTI_Line = EXTI_Line0 | EXTI_Line1 | EXTI_Line2;
	EXTI_InitStruct->EXTI_LineCmd = ENABLE;
	EXTI_InitStruct->EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct->EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(EXTI_InitStruct);
}
