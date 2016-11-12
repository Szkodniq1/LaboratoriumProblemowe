#include "stm32f4xx_conf.h"
#include "GPIO.h"
#include "USART.h"
#include "EXTI.h"


int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;

	SystemInit();
	initGPIO(&GPIO_InitStructure);
	initUSART(&USART_InitStructure);
	initEXTI(&EXTI_InitStructure);

    while(1)
    {

    }
}
