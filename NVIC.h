#ifndef __NVIC_H
#define __NVIC_h

#include "misc.h"


void initNVIC(NVIC_InitTypeDef* NVIC_InitStruct);
void initSynchroInterrupt(NVIC_InitTypeDef* NVIC_InitStruct);
void initPCUARTInterrupt(NVIC_InitTypeDef* NVIC_InitStructure);
void initEncoderUARTInterrupt(NVIC_InitTypeDef* NVIC_InitStructure);
void initDroneUARTInterrupt(NVIC_InitTypeDef* NVIC_InitStructure);

#endif
