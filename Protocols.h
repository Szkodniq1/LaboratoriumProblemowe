#ifndef __PROTOCOLS_H
#define __PROTOCOLS_H

#include "main.h"
#include "USART.h"
#include "SOLVER.h"

//PC
#define START_PC (char)0x00
#define STOP_PC (char)0x10
#define LOWER_P (char)0x20
#define UPPER_P (char)0x30
#define LOWER_I (char)0x40
#define UPPER_I (char)0x50
#define LOWER_D (char)0x60
#define UPPER_D (char)0x70
#define P_SETTINGS (char)0x80
#define I_SETTINGS (char)0x90
#define D_SETTINGS (char)0xA0
#define STATUS_PC (char)0xB0
#define ERROR_PC (char)0xC0

//UC
#define START_UC (char)0x00
#define STOP_UC (char)0x10
#define ANGLE_ENC (char)0x20
#define ANGLE_DRONE (char)0x30
#define ANGLE_SET (char)0x40
#define CURRENT_P (char)0x50
#define CURRENT_I (char)0x60
#define CURRENT_D (char)0x70
#define TIME (char)0x80
#define STATUS_UC (char)0x90
#define ERROR_UC (char)0xA0
#define DATA_OBTAINED (char)0xB0
#define CONNECTED (char)0xC0

#define HEADER 0
#define DATA 1

char pcFrameType;
char receivedData;

void solvePCRequest(char data);
void solvePCHeader(char data);
void solvePCData(char data);
void solveDroneRequest(char data);
void solveEncoderRequest(char data);

#endif
