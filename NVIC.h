#ifndef __NVIC_H
#define __NVIC_h

#include "misc.h"

void initNVIC(NVIC_InitTypeDef* NVIC_InitStruct);
void initSynchroInterrupt(NVIC_InitTypeDef* NVIC_InitStruct);
void initEncoderAInterrupt(NVIC_InitTypeDef* NVIC_InitStructure);
void initEncoderBInterrupt(NVIC_InitTypeDef* NVIC_InitStructure);
void initPCUARTInterrupt(NVIC_InitTypeDef* NVIC_InitStructure);
void initDroneUARTInterrupt(NVIC_InitTypeDef* NVIC_InitStructure);
void enableNVIC();
#endif
