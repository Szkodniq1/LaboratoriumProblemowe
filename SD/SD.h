#ifndef __SD_H
#define __SD_H

#include "defines.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_fatfs.h"
#include <stdio.h>
#include <string.h>
#include "GPIO.h"


//Fatfs object
FATFS FatFs;
//File object
FIL fil;

void test_sd();
void mount_card();
void unmount_card();
void save_meassurementes();

#endif
