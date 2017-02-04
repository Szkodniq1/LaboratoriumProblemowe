/**
\author Piotr Gomo³a
\date 4.02.2017

Zawiera funkcje testuj¹c¹ pracê karty SD (przetestowane, dzia³a³o). Jest ona wzorcem prawidlowego korzystania z karty SD.
Dodatkowo zawiera funkcje do montowania/odmontowywania karty oraz zapisu pomiarów na niej.

*/
#include "SD.h"

/** @brief Test dzia³ania zmontowania i zapisu danych na kartê SD.

Test przechodzi przez wszystkie aspekty dzia³ania karty SD, w celu sprawdzenia poprawnoci kodu mo¿na go uruchomiæ i sprawdziæ poprawnoæ dzia³ania.
Zawiera on te¿ wszystkie potrzebne elementy do przeprowadzenia tego typu operacji, jest wiêc wzorcem.

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

/** @brief Funkcja montuj¹ca kartê.

Mo¿e to zostaæ obs³u¿one przez jeden z przycisków, lub na starcie programu. Karta powinna zostaæ zamontowana raz, aby dalej dzia³aæ ju¿ w trybie ci¹g³ym.

 */
void mount_card() {
	if (f_mount(&FatFs, "", 1) == FR_OK) {
		GPIO_SetBits(GPIOB, CARD_MOUNTED);
	} else {
		GPIO_SetBits(GPIOB, CARD_NOT_MOUNTED);
	}
}

/** @brief Funkcja odmontowuj¹ca kartê.

Koniecznie wykonywana po zakoñczeniu testu, a na pewno przed jej wyjêciem / wy³¹czeniem zasilania uk³adu.

 */
void unmount_card() {
	f_mount(0, "", 1);
}

/** @brief Funkcja zapisuj¹ca.

Jest to template funkcji zapisuj¹cej, jak do tej pory nie mielimy ¿adnych danych które mo¿na by zapisaæ wiêc nie zosta³a ona nigdy skoñczona.

 */
void save_meassurementes() {
	if (f_open(&fil, "pomiary.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE) == FR_OK) {
		f_puts("First string in my file\n", &fil);
		f_close(&fil);
	}
}
