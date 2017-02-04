/**
\author Piotr Gomo³a
\date 4.02.2017

Plik inicjalizacji GPIO, zaweira te¿ intuicyjn¹ funkcjê do zapalania diod.

*/
#include "GPIO.h"

/** @brief Zbiorcza inicjalizacja wszystkich portów GPIO.

@param GPIO_InitStructure WskaŸnik do struktury inicjuj¹cej GPIO zadeklarowanej na pocz¹tku funkcji main programu.

Wykorzystywane s¹ porty A - wielozadaniowy, B - diody LED, C - przerwania, dron oraz karta SD po SDIO, E - obs³uga wejcia joysticka (5 przycisków).

 */
void initGPIO(GPIO_InitTypeDef* GPIO_InitStructure)
{
	initPortA(GPIO_InitStructure);
	initPortB(GPIO_InitStructure);
	initPortC(GPIO_InitStructure);
	initPortE(GPIO_InitStructure);
}

/** @brief Inicjalizacja portu A.

@param GPIO_InitStructure WskaŸnik do struktury inicjuj¹cej GPIO zadeklarowanej na pocz¹tku funkcji main programu.

Port A odpowiada za komunikacjê z komputerem po UART4 oraz ewentualn¹ obs³ugê SPI wejcia karty SD.

 */
void initPortA(GPIO_InitTypeDef* GPIO_InitStructure)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_UART4);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_UART4);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);


	GPIO_InitStructure->GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure->GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure->GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure->GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure->GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, GPIO_InitStructure);
}

/** @brief Inicjalizacja portu B.

@param GPIO_InitStructure WskaŸnik do struktury inicjuj¹cej GPIO zadeklarowanej na pocz¹tku funkcji main programu.

Port B odpowiada za 8 diod sygnalizacyjnych.

 */
void initPortB(GPIO_InitTypeDef* GPIO_InitStructure)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitStructure->GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure->GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure->GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure->GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure->GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, GPIO_InitStructure);
}

/** @brief Inicjalizacja portu C.

@param GPIO_InitStructure WskaŸnik do struktury inicjuj¹cej GPIO zadeklarowanej na pocz¹tku funkcji main programu.

Port C odpowiada komunikacjê z dronem po USART6 oraz przerwania synchronizacyjne i od enkodera.

 */
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

	GPIO_InitStructure->GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure->GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure->GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure->GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure->GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, GPIO_InitStructure);
}

/** @brief Inicjalizacja portu E.

@param GPIO_InitStructure WskaŸnik do struktury inicjuj¹cej GPIO zadeklarowanej na pocz¹tku funkcji main programu.

Port E odpowiada za obs³ugê wejsæ od joysticka.

 */
void initPortE(GPIO_InitTypeDef* GPIO_InitStructure)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	GPIO_InitStructure->GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure->GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure->GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure->GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure->GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOE, GPIO_InitStructure);
}

/** @brief Funkcja zapalaj¹ca diodê.

@param diode numer pinu diody podawany w specjalnym makrze.

Tkaa funkcja jest bardziej opisowa - jej nazwa od razu t³umaczy jej dzia³anie.

 */
void lightDiode(uint16_t diode) {
	GPIO_SetBits(GPIOB, diode);
}
