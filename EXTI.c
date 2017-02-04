/**
\author Piotr Gomo³a
\date 4.02.2017

Plik inicjalizacji przerwañ zewnêtrznych.

*/
#include "EXTI.h"

/** @brief Konfiguracja linii przerwañ zewnêtrznych pod³¹czonych do p³ytki.

@param EXTI_InitStruct WskaŸnik do struktury inicjuj¹cej EXTI zadeklarowanej na pocz¹tku funkcji main programu.

Jest to linia 0, 1 i 2 s³u¿¹ce kolejno do synchronizacji z dronem, zliczania impulsów od drona na linii A,
zliczania impulsów od drona na linii B.

 */
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
