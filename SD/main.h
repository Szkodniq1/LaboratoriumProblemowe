#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f4xx_conf.h"
#include "GPIO.h"
#include "USART.h"
#include "EXTI.h"
#include "NVIC.h"
#include "SD.h"
#include <PROTOCOLS.h>
#include "SOLVER.h"

void EXTI0_IRQHandler(void);
void UART4_IRQHandler(void);
void USART1_IRQHandler(void);
void USART6_IRQHandler(void);
int main(void);

#endif
