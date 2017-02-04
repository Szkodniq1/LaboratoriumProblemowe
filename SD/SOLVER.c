/**
\author Piotr Gomo³a
\date 4.02.2017

W zamysle, interfejs do obs³ugi wybranych bibliotek. Jego ide¹ by³o ³atwe przepinanie siê pomidzy u¿ywanymi bibliotekami,
najlepiej z wykorzystaniem przycisków (przeskok pomiêdzy algorytmami)

*/
#include "SOLVER.h"

/** @brief Inicjacja solvera - konkretnej biblioteki do obliczania parametrow.

Funkcja maj¹ca na celu dynamiczne przerzucanie siê z inicjalizacji algorytmu do obliczania na podstawie smiany jednego parametru w pliku nag³ówkowym.
¯aden algorytm nie zosta³ nigdy napisany a wiêc funkcja jest pusta.

 */
void initSolver(){
	if(SET_LIBRARY == TOMKOWA_BIBLIOTEKA) {

	} else if (SET_LIBRARY == KUKSOWO_LASAKOWA_BIBLOTEKA) {

	}
}

/** @brief Obliczanie parametrów wg konkretnej biblioteki.

Funkcja maj¹ca na celu dynamiczne obliczanie parametrów regulatora na podstawie metody wybranej w pliku nag³ówkowym.
¯aden algorytm nie zosta³ nigdy napisany a wiêc funkcja jest pusta.

 */
void solveRegulatorParams(){
	if(SET_LIBRARY == TOMKOWA_BIBLIOTEKA) {

	} else if (SET_LIBRARY == KUKSOWO_LASAKOWA_BIBLOTEKA) {

	}
}
