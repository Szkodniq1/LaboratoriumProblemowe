#include "SD.h"
/*
void test_sd()
{
	//Free and total space
	uint32_t total, free;
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

void mount_card() {
	if (f_mount(FatFs, "", 1) == FR_OK) {
		GPIO_SetBits(GPIOB, CARD_MOUNTED);
	} else {
		GPIO_SetBits(GPIOB, CARD_NOT_MOUNTED);
	}
}

void unmount_card() {
	f_mount(0, "", 1);
}

void save_meassurementes() {
	if (f_open(fil, "pomiary.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE) == FR_OK) {
		f_puts("First string in my file\n", fil);
		f_close(fil);
	}
}
*/
