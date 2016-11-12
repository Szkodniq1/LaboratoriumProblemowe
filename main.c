#include "stm32f4xx_conf.h"
#include "GPIO.h"
#include "USART.h"


int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	SystemInit();
	initGPIO(&GPIO_InitStructure);
	initUSART(&USART_InitStructure);


    while(1)
    {

    }
}
