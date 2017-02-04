/**
\author Piotr Gomo�a
\date 4.02.2017

Plik inicjalizacji przerwa� zewn�trznych.

*/
#include "EXTI.h"

/** @brief Konfiguracja linii przerwa� zewn�trznych pod��czonych do p�ytki.

@param EXTI_InitStruct Wska�nik do struktury inicjuj�cej EXTI zadeklarowanej na pocz�tku funkcji main programu.

Jest to linia 0, 1 i 2 s�u��ce kolejno do synchronizacji z dronem, zliczania impuls�w od drona na linii A,
zliczania impuls�w od drona na linii B.

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
