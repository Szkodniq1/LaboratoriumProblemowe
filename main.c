/**
\author Piotr Gomo³a
\date 4.02.2017

Plik main zawiera funkcje main oraz handlery od przerwañ.

*/
#include "main.h"

double encoderPos = 0.0;
double encoderAngle = 0.0;
char dirA=0, dirB=0;

/** @brief Funkcja g³ówna programu.

Jak narazie dokonuje inicjalizacji oraz oblicza w pêtli k¹t z enkodera, k¹t nie jest nigdzie wysylanny/zapisywany,
mo¿na to dodac jedna linijka korzystajac z funkcji zawartych w USART.c lub SD.c w zaleznosci preferencji (czy wysylac do PC czy zapisywaæ na karcie).

 */
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
    	encoderAngle = encoderPos * 360.0;
    }
}

/** @brief Przerwanie od pinu synchronizacji komunikacji z dronem.

Do drona przygotowane zosta³o gniazdo z czterema wejsciami/wyjsciami TX,RX,GND i w³anie SYNCHRO,
odpowiedzialne ze poprawn¹ akredytacje danych na temat k¹ta.

 */
void EXTI0_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line0) != RESET) {

        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

/** @brief Przerwanie od enkodera na linii A.

Oznacza to przyjêty umownie kierunek zgodny ze wskazówkami zegara. Zasada dzia³ania:
jesli przerwanie na linii A pojawia siê przed przerwaniem na linii B (przesuniêtej o 90 stopni)
to oznacza to i¿ enkoder obraca siê zgodnie ze wskazówkami zegara, k¹t jest dodawany do wartosci.

 */
void EXTI1_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line1) != RESET) {
    	if(dirB == 0) {
    	    dirA = 1;
    	    encoderPos = encoderPos + ENCODER_RESOLUTION;
    	} else {
    		dirB = 0;
    	}
        EXTI_ClearITPendingBit(EXTI_Line1);
    }
}

/** @brief Przerwanie od enkodera na linii B (przesuniêtej wzgledem A o 90 stopni).

Oznacza to przyjêty umownie kierunek przeciwny do kierunku wskazówek zegara. Zasada dzia³ania:
jesli przerwanie na linii B pojawia siê przed przerwaniem na linii A
to oznacza to i¿ enkoder obraca siê przeciwnie do wskazowek zegara, k¹t jest odejmowany od wartosci.

 */
void EXTI2_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line2) != RESET) {
    	if(dirA == 0) {
    	    dirB = 1;
    	    encoderPos = encoderPos - ENCODER_RESOLUTION;
    	} else {
    		dirA = 0;
    	}
        EXTI_ClearITPendingBit(EXTI_Line2);
    }
}

/** @brief Przerwanie od UART4 - przerwanie od komputera.

Dane ortzymywane od komputera przetwarzane s¹ w specjalnej funkcji solvePCRequest znajduj¹cej siê w
pliku PROTOCOLS.C.

 */
void UART4_IRQHandler(void)
{
	if (USART_GetFlagStatus(UART4, USART_FLAG_RXNE))
	{
		solvePCRequest(USART_ReceiveData(UART4));
	}
	USART_ClearITPendingBit(UART4, USART_IT_RXNE);
}

/** @brief Przerwanie od USART6 - przerwanie od drona.

Dane ortzymywane od komputera przetwarzane s¹ w specjalnej funkcji solveDroneRequest znajduj¹cej siê w
pliku PROTOCOLS.C.

 */
void USART6_IRQHandler(void)
{
	if (USART_GetFlagStatus(USART6, USART_FLAG_RXNE))
	{
		solveDroneRequest(USART_ReceiveData(USART6));
	}
	USART_ClearITPendingBit(USART6, USART_IT_RXNE);
}
