/**
\author Piotr Gomo�a
\date 4.02.2017

Plik inicjalizacji przerwa� od NVIC.

*/
#include "NVIC.h"

/** @brief Zbiorcza inicjalizacja wszystkich przerwa�.

@param NVIC_InitStructure Wska�nik do struktury inicjuj�cej NVIC zadeklarowanej na pocz�tku funkcji main programu.

S� to przerwania kolejno od: synchronizacji z dronem, szyny A od enkodera, szyny B od enkodera, UART od komputera, UART od drona.

 */
void initNVIC(NVIC_InitTypeDef* NVIC_InitStructure)
{
	initSynchroInterrupt(NVIC_InitStructure);
	initEncoderAInterrupt(NVIC_InitStructure);
	initEncoderBInterrupt(NVIC_InitStructure);
	initPCUARTInterrupt(NVIC_InitStructure);
	initDroneUARTInterrupt(NVIC_InitStructure);
	enableNVIC();
}

/** @brief Inicjalizacja przerwania od pinu synchronizuj�cego komunikacj� z dronem.

@param NVIC_InitStructure Wska�nik do struktury inicjuj�cej NVIC zadeklarowanej na pocz�tku funkcji main programu.

Jest to linia 0 na porcie C.

 */
void initSynchroInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStructure->NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure->NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(NVIC_InitStructure);
}

/** @brief Inicjalizacja przerwania od pary A enkodera.

@param NVIC_InitStructure Wska�nik do struktury inicjuj�cej NVIC zadeklarowanej na pocz�tku funkcji main programu.

Jest to linia 1 na porcie C.

 */
void initEncoderAInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStructure->NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStructure->NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(NVIC_InitStructure);
}

/** @brief Inicjalizacja przerwania od pary B enkodera.

@param NVIC_InitStructure Wska�nik do struktury inicjuj�cej NVIC zadeklarowanej na pocz�tku funkcji main programu.

Jest to linia 2 na porcie C.

 */
void initEncoderBInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStructure->NVIC_IRQChannel = EXTI2_IRQn;
	NVIC_InitStructure->NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(NVIC_InitStructure);
}

/** @brief Inicjalizacja przerwania od UART4 s�u��cego do komunikacji z komputerem.

@param NVIC_InitStructure Wska�nik do struktury inicjuj�cej NVIC zadeklarowanej na pocz�tku funkcji main programu.

 */
void initPCUARTInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStructure->NVIC_IRQChannel = UART4_IRQn;
	NVIC_InitStructure->NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure->NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(NVIC_InitStructure);
}

/** @brief Inicjalizacja przerwania od USART6 s�u��cego do komunikacji z dronem.

@param NVIC_InitStructure Wska�nik do struktury inicjuj�cej NVIC zadeklarowanej na pocz�tku funkcji main programu.

 */
void initDroneUARTInterrupt(NVIC_InitTypeDef* NVIC_InitStructure)
{
	NVIC_InitStructure->NVIC_IRQChannel = USART6_IRQn;
	NVIC_InitStructure->NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure->NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure->NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(NVIC_InitStructure);
}

/** @brief Globalne zezwolenie na przerwania.

Funkcja wykonywana jest na samym ko�cu procedury inicjalizacji w main(), tu� przed rozpocz�ciem regularnej pracy w niesko�czonej p�tli.

 */
void enableNVIC() {
	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_EnableIRQ(UART4_IRQn);
	NVIC_EnableIRQ(USART6_IRQn);
}
