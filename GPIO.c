#include "GPIO.h"

void initGPIO(GPIO_InitTypeDef* GPIO_InitStructure)
{
	initPortA(GPIO_InitStructure);
	initPortB(GPIO_InitStructure);
	initPortC(GPIO_InitStructure);
	initPortE(GPIO_InitStructure);
}

void initPortA(GPIO_InitTypeDef* GPIO_InitStructure)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_UART4);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_UART4);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

	GPIO_InitStructure->GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_InitStructure->GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure->GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure->GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure->GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, GPIO_InitStructure);
}

void initPortB(GPIO_InitTypeDef* GPIO_InitStructure)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitStructure->GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure->GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure->GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure->GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure->GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, GPIO_InitStructure);
}

void initPortC(GPIO_InitTypeDef* GPIO_InitStructure)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);

	GPIO_InitStructure->GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure->GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure->GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure->GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure->GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, GPIO_InitStructure);

	GPIO_InitStructure->GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure->GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure->GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure->GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure->GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, GPIO_InitStructure);
}

void initPortE(GPIO_InitTypeDef* GPIO_InitStructure)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	//TODO gdy bêd¹ wiadome

}
