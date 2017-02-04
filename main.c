/**
\author Piotr Gomo�a
\date 4.02.2017

Plik main zawiera funkcje main oraz handlery od przerwa�.

*/
#include "main.h"

double encoderPos = 0.0;
double encoderAngle = 0.0;
char dirA=0, dirB=0;

/** @brief Funkcja g��wna programu.

Jak narazie dokonuje inicjalizacji oraz oblicza w p�tli k�t z enkodera, k�t nie jest nigdzie wysylanny/zapisywany,
mo�na to dodac jedna linijka korzystajac z funkcji zawartych w USART.c lub SD.c w zaleznosci preferencji (czy wysylac do PC czy zapisywa� na karcie).

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

Do drona przygotowane zosta�o gniazdo z czterema wejsciami/wyjsciami TX,RX,GND i w�anie SYNCHRO,
odpowiedzialne ze poprawn� akredytacje danych na temat k�ta.

 */
void EXTI0_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line0) != RESET) {

        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

/** @brief Przerwanie od enkodera na linii A.

Oznacza to przyj�ty umownie kierunek zgodny ze wskaz�wkami zegara. Zasada dzia�ania:
jesli przerwanie na linii A pojawia si� przed przerwaniem na linii B (przesuni�tej o 90 stopni)
to oznacza to i� enkoder obraca si� zgodnie ze wskaz�wkami zegara, k�t jest dodawany do wartosci.

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

/** @brief Przerwanie od enkodera na linii B (przesuni�tej wzgledem A o 90 stopni).

Oznacza to przyj�ty umownie kierunek przeciwny do kierunku wskaz�wek zegara. Zasada dzia�ania:
jesli przerwanie na linii B pojawia si� przed przerwaniem na linii A
to oznacza to i� enkoder obraca si� przeciwnie do wskazowek zegara, k�t jest odejmowany od wartosci.

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

Dane ortzymywane od komputera przetwarzane s� w specjalnej funkcji solvePCRequest znajduj�cej si� w
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

Dane ortzymywane od komputera przetwarzane s� w specjalnej funkcji solveDroneRequest znajduj�cej si� w
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
