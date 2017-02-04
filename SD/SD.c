/**
\author Piotr Gomo�a
\date 4.02.2017

Zawiera funkcje testuj�c� prac� karty SD (przetestowane, dzia�a�o). Jest ona wzorcem prawidlowego korzystania z karty SD.
Dodatkowo zawiera funkcje do montowania/odmontowywania karty oraz zapisu pomiar�w na niej.

*/
#include "SD.h"

/** @brief Test dzia�ania zmontowania i zapisu danych na kart� SD.

Test przechodzi przez wszystkie aspekty dzia�ania karty SD, w celu sprawdzenia poprawnoci kodu mo�na go uruchomi� i sprawdzi� poprawno� dzia�ania.
Zawiera on te� wszystkie potrzebne elementy do przeprowadzenia tego typu operacji, jest wi�c wzorcem.

 */
void test_sd()
{
	//Free and total space
	uint32_t total, free;
    //Initialize delays
    TM_DELAY_Init();

    GPIO_SetBits(GPIOB, GPIO_Pin_1);
    //Mount drive
    if (f_mount(&FatFs, "", 1) == FR_OK) {
        //Mounted OK, turn on RED LED
    	GPIO_SetBits(GPIOB, GPIO_Pin_2);

        //Try to open file
        if (f_open(&fil, "1stfile.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE) == FR_OK) {
            //File opened, turn off RED and turn on GREEN led
        	GPIO_SetBits(GPIOB, GPIO_Pin_3);

            //If we put more than 0 characters (everything OK)
            if (f_puts("First string in my file\n", &fil) > 0) {
                if (TM_FATFS_DriveSize(total, free) == FR_OK) {
                    //Data for drive size are valid
                	GPIO_SetBits(GPIOB, GPIO_Pin_5);
                }
                GPIO_SetBits(GPIOB, GPIO_Pin_4);
            }

            //Close file, don't forget this!
            f_close(&fil);
        }

        //Unmount drive, don't forget this!
        f_mount(0, "", 1);
    }
}

/** @brief Funkcja montuj�ca kart�.

Mo�e to zosta� obs�u�one przez jeden z przycisk�w, lub na starcie programu. Karta powinna zosta� zamontowana raz, aby dalej dzia�a� ju� w trybie ci�g�ym.

 */
void mount_card() {
	if (f_mount(&FatFs, "", 1) == FR_OK) {
		GPIO_SetBits(GPIOB, CARD_MOUNTED);
	} else {
		GPIO_SetBits(GPIOB, CARD_NOT_MOUNTED);
	}
}

/** @brief Funkcja odmontowuj�ca kart�.

Koniecznie wykonywana po zako�czeniu testu, a na pewno przed jej wyj�ciem / wy��czeniem zasilania uk�adu.

 */
void unmount_card() {
	f_mount(0, "", 1);
}

/** @brief Funkcja zapisuj�ca.

Jest to template funkcji zapisuj�cej, jak do tej pory nie mielimy �adnych danych kt�re mo�na by zapisa� wi�c nie zosta�a ona nigdy sko�czona.

 */
void save_meassurementes() {
	if (f_open(&fil, "pomiary.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE) == FR_OK) {
		f_puts("First string in my file\n", &fil);
		f_close(&fil);
	}
}
