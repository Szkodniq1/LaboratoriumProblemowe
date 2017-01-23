#include "main.h"

int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	SystemInit();
	initGPIO(&GPIO_InitStructure);
	initUSART(&USART_InitStructure);
	initEXTI(&EXTI_InitStructure);
	initNVIC(&NVIC_InitStructure);
	initSolver();

	lightDiode(DEVICE_ON);
	STATE = STATE_IDLE;

    while(1)
    {

    }
}

//Przerwanie od synchro z drona
void EXTI0_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line0) != RESET) {

        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

//Przerwanie od enkodera A
void EXTI1_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line1) != RESET) {

        EXTI_ClearITPendingBit(EXTI_Line1);
    }
}

//Przerwanie od enkodera B (przesuniete o 90st)
void EXTI2_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line2) != RESET) {

        EXTI_ClearITPendingBit(EXTI_Line2);
    }
}

//Przerwanie od komputera
void UART4_IRQHandler(void)
{
	if (USART_GetFlagStatus(UART4, USART_FLAG_RXNE))
	{
		solvePCRequest(USART_ReceiveData(UART4));
	}
	USART_ClearITPendingBit(UART4, USART_IT_RXNE);
}

//Przerwanie od drona
void USART6_IRQHandler(void)
{
	if (USART_GetFlagStatus(USART6, USART_FLAG_RXNE))
	{
		solveDroneRequest(USART_ReceiveData(USART6));
	}
	USART_ClearITPendingBit(USART6, USART_IT_RXNE);
}
