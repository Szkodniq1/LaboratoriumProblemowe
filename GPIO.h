#ifndef __GPIO_H
#define __GPIO_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

void initGPIO(GPIO_InitTypeDef* GPIO_InitStructure);
void initPortA(GPIO_InitTypeDef* GPIO_InitStructure);
void initPortB(GPIO_InitTypeDef* GPIO_InitStructure);
void initPortC(GPIO_InitTypeDef* GPIO_InitStructure);
void initPortE(GPIO_InitTypeDef* GPIO_InitStructure);

#endif
