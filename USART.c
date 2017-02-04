/**
\author Piotr Gomo³a
\date 4.02.2017

Zawarte s¹ tu funkcje inicjuj¹ce poszczególne interfejsy UART oraz
funkcje s³u¿¹ce do przesylania roznego rodzaju danych.

*/
#include "USART.h"

/** @brief Funkcja inicjuj¹ca pracê UART.

@param USART_InitStructure Struktura inicjujaca UART zadeklarowana na pocz¹tku funkcji main().

Inicjowana jest komunikacja z komputerem i dronem.

 */
void initUSART(USART_InitTypeDef* USART_InitStructure)
{
	initPCUART(USART_InitStructure);
	initDroneUSART(USART_InitStructure);
}

/** @brief Funkcja inicjuj¹ca komunikacje z komputerem.

@param USART_InitStructure Struktura inicjujaca UART zadeklarowana na pocz¹tku funkcji main().

Komunikacja przebiega po UART4.

 */
void initPCUART(USART_InitTypeDef* USART_InitStructure) {
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);

	USART_Cmd(UART4, ENABLE);

	USART_InitStructure->USART_BaudRate = UART_BAUDRATE;
	USART_InitStructure->USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure->USART_Parity = USART_Parity_No;
	USART_InitStructure->USART_StopBits = USART_StopBits_1;
	USART_InitStructure->USART_WordLength = USART_WordLength_8b;
	USART_InitStructure->USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(UART4, USART_InitStructure);

	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
}

/** @brief Funkcja inicjuj¹ca komunikacje z dronem.

@param USART_InitStructure Struktura inicjujaca UART zadeklarowana na pocz¹tku funkcji main().

Komunikacja przebiega po USART6.

 */
void initDroneUSART(USART_InitTypeDef* USART_InitStructure) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);

	USART_Cmd(USART6, ENABLE);

	USART_InitStructure->USART_BaudRate = UART_BAUDRATE;
	USART_InitStructure->USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure->USART_Parity = USART_Parity_No;
	USART_InitStructure->USART_StopBits = USART_StopBits_1;
	USART_InitStructure->USART_WordLength = USART_WordLength_8b;
	USART_InitStructure->USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART6, USART_InitStructure);

	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);
}

/** @brief Przesylajaca dane typu char po wybranym interfejsie.

@param USARTx Interfejs po którym maja byc wysylane dane.
@param ch Wysylany znak char.

 */
void USART_put_char(USART_TypeDef* USARTx, uint8_t ch)
{
	while(!(USARTx->SR & USART_SR_TXE));
	USARTx->DR = ch;
}

/** @brief Przesylajaca ci¹g znakow po wybranym interfejsie.

@param USARTx Interfejs po którym maja byc wysylane dane.
@param s Wysylany ciag znakow.

 */
void USART_put_string(USART_TypeDef* USARTx, volatile char *s){
	while(*s){
		while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);
		USART_SendData(USARTx, *s);
		*s++;
	}
}

/** @brief Przesylajaca wartosc typu float po wybranym interfejsie.

@param USARTx Interfejs po którym maja byc wysylane dane.
@param f Wysylana wartosc typu float.

 */
void USART_put_float(USART_TypeDef* USARTx, float f){
	int i = 0;
	char convertedFloat[4];
	sprintf(convertedFloat, "%f", f);
	for(i ; i < 4 ; i++) {
		USART_put_char(USARTx, convertedFloat[i]);
	}
}

/** @brief Przesylajaca wartosc typu long po wybranym interfejsie.

@param USARTx Interfejs po którym maja byc wysylane dane.
@param l Wysylana wartosc typu long.

 */
void USART_put_long(USART_TypeDef* USARTx, unsigned long l){
	int i = 0;
	char convertedLong[4];
	sprintf(convertedLong, "%lu", l);
	for(i ; i < 4; i++) {
		USART_put_char(USARTx, convertedLong[i]);
	}
}

