#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f4xx_conf.h"
#include "GPIO.h"
#include "USART.h"
#include "EXTI.h"
#include "NVIC.h"
#include "SD.h"
#include "SOLVER.h"

#define STATE_IDLE 0
#define STATE_WORKING 1

#define ENCODER_RESOLUTION (1.0/2500.0)


char STATE;

void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void UART4_IRQHandler(void);
void USART1_IRQHandler(void);
void USART6_IRQHandler(void);
int main(void);

#endif
