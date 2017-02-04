/**
\author Piotr Gomo³a
\date 4.02.2017

Zawiera funkcje do odbioru i rozpatrywania otrzymywanych danych oraz
funkcje przesy³aj¹ce dane.

*/
#include "PROTOCOLS.h"

/** @brief Funkcja obs³ugi danych otrzymywanych od PC.

@param data Otrzymany bajt danych.

Funkcja ta rozpatruje czy otrzymany bajt jest nag³ówkiem, mówi¹cym o tym jaka akcja ma byæ wykonana lub jakie dane maj¹ byæ otrzymane/wys³ane.
Jesli nie jest nag³ówkiem oznacza to ¿e otrzymywane s¹ aktualnie jakie dane.

 */
void solvePCRequest(char data) {
	if(pcFrameType == HEADER) {
		solvePCHeader(data);
	} else {
		solvePCData(data);
	}
}

/** @brief Funkcja obs³ugi nag³ówka otrzymywanego od PC.

@param data Otrzymany bajt danych.

Nag³ówek jest zapamiêtywany w celu odpowiedniego rozpatrywania pozniej otrzymywanych danych. Protokó³ komunikacji zostal opisany
pod linkiem:
https://docs.google.com/spreadsheets/d/1Z8SAWWgW5sYVVg0G66wHbE4FpKFIf1aW96YlPKJvAEY/edit#gid=0

 */
void solvePCHeader(char data){
	switch(data) {
		case START_PC:
			STATE = STATE_WORKING;
			USART_put_char(PC, START_UC);
			break;
		case STOP_PC:
			STATE = STATE_IDLE;
			USART_put_char(PC, STOP_UC);
			break;
		case LOWER_P:
			pcFrameType = DATA;
			receivedData = LOWER_P;
			break;
		case UPPER_P:
			pcFrameType = DATA;
			receivedData = UPPER_P;
			break;
		case LOWER_I:
			pcFrameType = DATA;
			receivedData = LOWER_I;
			break;
		case UPPER_I:
			pcFrameType = DATA;
			receivedData = UPPER_I;
			break;
		case LOWER_D:
			pcFrameType = DATA;
			receivedData = LOWER_D;
			break;
		case UPPER_D:
			pcFrameType = DATA;
			receivedData = UPPER_D;
			break;
		case P_SETTINGS:
			pcFrameType = DATA;
			receivedData = P_SETTINGS;
			break;
		case I_SETTINGS:
			pcFrameType = DATA;
			receivedData = I_SETTINGS;
			break;
		case D_SETTINGS:
			pcFrameType = DATA;
			receivedData = D_SETTINGS;
			break;
		case STATUS_PC:
			break;
		case ERROR_PC:
			break;
		default:
			break;
	}
}

/** @brief Funkcja obs³ugi danych otrzymywanego od PC.

@param data Otrzymany bajt danych.

Wszystkie dane wysy³ane s¹ w zmiennych zajmuj¹cych 4 bajty (float) dlatego w pierwszej kolejnosci
odbioreane sa 4 bajty danych. Tablica ta na koncu trafia do funkcji decyduj¹cej do jakiej zmiennej zapisaæ te dane.

 */
void solvePCData(char data){
	frame[shiftedIndex] = data;
	shiftedIndex++;
	if(shiftedIndex == 4) {
		shiftedIndex = 0;
		pcFrameType = HEADER;
		saveDataInProperVariable(atof(frame));
	}
}

/** @brief Funkcja decydujaca gdzie zapisaæ dane.

@param value Otrzymana wartosc.

Na podstawie wczesniej zapisanego naglowka, wartosc przypisywana jest do odpowiedniej zmiennej.

 */
void saveDataInProperVariable(float value) {
	switch(receivedData) {
			case LOWER_P:
				lowerP = value;
				break;
			case UPPER_P:
				upperP = value;
				break;
			case LOWER_I:
				lowerI = value;
				break;
			case UPPER_I:
				upperI = value;
				break;
			case LOWER_D:
				lowerD = value;
				break;
			case UPPER_D:
				upperD = value;
				break;
			case P_SETTINGS:
				P = value;
				break;
			case I_SETTINGS:
				I = value;
				break;
			case D_SETTINGS:
				D = value;
				break;
			default:
				break;
		}
}

/** @brief Pojedyncza funkcja wysy³aj¹ca ci¹giem wszystkie dane do komputera.

P³ytka wysy³a: k¹t z drona, k¹t z enkodera, k¹t ustawiony, aktualny parametr p, i oraz d, czas symulacji.

 */
void sendAllDataToPC() {
	//k¹ty
	USART_put_char(PC, ANGLE_DRONE);
	USART_put_float(PC, angleDrone);
	USART_put_char(PC, ANGLE_ENC);
	USART_put_float(PC, angleEncoder);
	USART_put_char(PC, ANGLE_SET);
	USART_put_float(PC, angleSet);
	//parametry pid
	USART_put_char(PC, CURRENT_P);
	USART_put_float(PC, P);
	USART_put_char(PC, CURRENT_I);
	USART_put_float(PC, I);
	USART_put_char(PC, CURRENT_D);
	USART_put_float(PC, D);
	//czas
	USART_put_char(PC, TIME);
	USART_put_long(PC, time);
}

/** @brief Funkcja rozpatruj¹ca dane otrzymywane od drona.

@param data Otrzymany bajt danych.

Brak implementacji ze wzglêdu na brak danych dotycz¹cych komunikacji z dronem.

 */
void solveDroneRequest(char data) {

}
