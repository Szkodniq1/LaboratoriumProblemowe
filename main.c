#include "stm32f4xx_conf.h"
#include "GPIO.h"
#include "USART.h"
#include "EXTI.h"
#include "NVIC.h"

//Przerwanie od synchro z drona
void EXTI0_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line0) != RESET) {

        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

//Przerwanie od komputera
void UART4_IRQHandler(void)
{
	if(USART_GetITStatus(UART4, USART_IT_RXNE) != RESET)
	{

	}
}

//Przerwanie od enkodera
void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{

	}
}

//Przerwanie od drona
void USART6_IRQHandler(void)
{
	if(USART_GetITStatus(USART6, USART_IT_RXNE) != RESET)
	{

	}
}


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

    while(1)
    {

    }
}
