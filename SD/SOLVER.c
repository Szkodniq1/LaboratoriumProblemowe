/**
\author Piotr Gomo�a
\date 4.02.2017

W zamysle, interfejs do obs�ugi wybranych bibliotek. Jego ide� by�o �atwe przepinanie si� pomidzy u�ywanymi bibliotekami,
najlepiej z wykorzystaniem przycisk�w (przeskok pomi�dzy algorytmami)

*/
#include "SOLVER.h"

/** @brief Inicjacja solvera - konkretnej biblioteki do obliczania parametrow.

Funkcja maj�ca na celu dynamiczne przerzucanie si� z inicjalizacji algorytmu do obliczania na podstawie smiany jednego parametru w pliku nag��wkowym.
�aden algorytm nie zosta� nigdy napisany a wi�c funkcja jest pusta.

 */
void initSolver(){
	if(SET_LIBRARY == TOMKOWA_BIBLIOTEKA) {

	} else if (SET_LIBRARY == KUKSOWO_LASAKOWA_BIBLOTEKA) {

	}
}

/** @brief Obliczanie parametr�w wg konkretnej biblioteki.

Funkcja maj�ca na celu dynamiczne obliczanie parametr�w regulatora na podstawie metody wybranej w pliku nag��wkowym.
�aden algorytm nie zosta� nigdy napisany a wi�c funkcja jest pusta.

 */
void solveRegulatorParams(){
	if(SET_LIBRARY == TOMKOWA_BIBLIOTEKA) {

	} else if (SET_LIBRARY == KUKSOWO_LASAKOWA_BIBLOTEKA) {

	}
}
