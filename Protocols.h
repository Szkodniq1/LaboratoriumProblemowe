#ifndef __PROTOCOLS_H
#define __PROTOCOLS_H

//PC
#define START_PC = 0x00;
#define STOP_PC = 0x10;
#define LOWER_P = 0x20;
#define UPPER_P = 0x30;
#define LOWER_I = 0x40;
#define UPPER_I = 0x50;
#define LOWER_D = 0x60;
#define UPPER_D = 0x70;
#define P_SETTINGS = 0x80;
#define I_SETTINGS = 0x90;
#define D_SETTINGS = 0xA0;
#define STATUS_PC = 0xB0;
#define ERROR_PC = 0xC0;

//UC
#define START_UC = 0x00;
#define STOP_UC = 0x10;
#define ANGLE_ENC = 0x20;
#define ANGLE_DRONE = 0x30;
#define ANGLE_SET = 0x40;
#define CURRENT_P = 0x50;
#define CURRENT_I = 0x60;
#define CURRENT_D = 0x70;
#define TIME = 0x80;
#define STATUS_UC = 0x90;
#define ERROR_UC = 0xA0;
#define DATA_OBTAINED = 0xB0;
#define CONNECTED = 0xC0;

void solvePCRequest(char data);
void solveDroneRequest(char data);
void solveEncoderRequest(char data);

#endif
