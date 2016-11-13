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
	uint8_t data;
	if (USART_GetFlagStatus(UART4, USART_FLAG_RXNE))
	{
		data = USART_ReceiveData(UART4);
		if(data == 'f')
		{
			USART_put(UART4, "UART4 here\r\n");
		}

	}
	USART_ClearITPendingBit(UART4, USART_IT_RXNE);
}

//Przerwanie od enkodera
void USART1_IRQHandler(void)
{
	uint8_t data;
		if (USART_GetFlagStatus(USART1, USART_FLAG_RXNE))
		{
			data = USART_ReceiveData(USART1);
			if(data == 'g')
			{
				USART_put(USART1, "USART1 here\r\n");
			}

		}
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
}

//Przerwanie od drona
void USART6_IRQHandler(void)
{
	uint8_t data;
	if (USART_GetFlagStatus(USART6, USART_FLAG_RXNE))
	{
		data = USART_ReceiveData(USART6);
		if(data == 'h')
		{
			USART_put(USART6, "USART6 here\r\n");
		}

	}
	USART_ClearITPendingBit(USART6, USART_IT_RXNE);
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
