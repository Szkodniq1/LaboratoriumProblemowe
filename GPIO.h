#ifndef __GPIO_H
#define __GPIO_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

#define DEVICE_ON GPIO_Pin_0
#define WORKING GPIO_Pin_1
#define CARD_MOUNTED GPIO_Pin_2
#define CARD_NOT_MOUNTED GPIO_Pin_3

void initGPIO(GPIO_InitTypeDef* GPIO_InitStructure);
void initPortA(GPIO_InitTypeDef* GPIO_InitStructure);
void initPortB(GPIO_InitTypeDef* GPIO_InitStructure);
void initPortC(GPIO_InitTypeDef* GPIO_InitStructure);
void initPortE(GPIO_InitTypeDef* GPIO_InitStructure);
void lightDiode(uint16_t diode);

#endif
