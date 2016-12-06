#include "defines.h"
#include "stm32f4xx_conf.h"
#include "GPIO.h"
#include "USART.h"
#include "EXTI.h"
#include "NVIC.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_disco.h"
#include "tm_stm32f4_fatfs.h"
#include <stdio.h>
#include <string.h>

//Fatfs object
FATFS FatFs;
//File object
FIL fil;

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

void light_leds()
{
	GPIO_SetBits(GPIOB, GPIO_Pin_0);
	//GPIO_SetBits(GPIOB, GPIO_Pin_1);
	//GPIO_SetBits(GPIOB, GPIO_Pin_2);
	//GPIO_SetBits(GPIOB, GPIO_Pin_3);
	//GPIO_SetBits(GPIOB, GPIO_Pin_4);
	//GPIO_SetBits(GPIOB, GPIO_Pin_5);
	//GPIO_SetBits(GPIOB, GPIO_Pin_6);
	//GPIO_SetBits(GPIOB, GPIO_Pin_7);
}

void test_sd(FATFS* FatFs, FIL* fil, uint32_t* total, uint32_t* free)
{
    //Initialize delays
    TM_DELAY_Init();

    GPIO_SetBits(GPIOB, GPIO_Pin_1);
    //Mount drive
    if (f_mount(FatFs, "", 1) == FR_OK) {
        //Mounted OK, turn on RED LED
    	GPIO_SetBits(GPIOB, GPIO_Pin_2);

        //Try to open file
        if (f_open(fil, "1stfile.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE) == FR_OK) {
            //File opened, turn off RED and turn on GREEN led
        	GPIO_SetBits(GPIOB, GPIO_Pin_3);

            //If we put more than 0 characters (everything OK)
            if (f_puts("First string in my file\n", fil) > 0) {
                if (TM_FATFS_DriveSize(total, free) == FR_OK) {
                    //Data for drive size are valid
                	GPIO_SetBits(GPIOB, GPIO_Pin_5);
                }
                GPIO_SetBits(GPIOB, GPIO_Pin_4);
            }

            //Close file, don't forget this!
            f_close(fil);
        }

        //Unmount drive, don't forget this!
        f_mount(0, "", 1);
    }
}


int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	//Free and total space
	uint32_t total, free;

	SystemInit();
	initGPIO(&GPIO_InitStructure);
	initUSART(&USART_InitStructure);
	initEXTI(&EXTI_InitStructure);
	initNVIC(&NVIC_InitStructure);

	light_leds();
	test_sd(&FatFs, &fil, &total, &free);

    while(1)
    {

    }
}
