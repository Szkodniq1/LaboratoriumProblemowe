#include "PROTOCOLS.h"

void solvePCRequest(char data) {
	if(pcFrameType == HEADER) {
		solvePCHeader(data);
	} else {
		solvePCData(data);
	}
}

void solvePCHeader(char data){
	switch(data) {
		case START_PC:
			STATE = STATE_WORKING;
			USART_put_char(PC, START_UC);
			break;
		case STOP_PC:
			STATE = STATE_IDLE;
			USART_put_char(PC, STOP_UC);
			break;
		case LOWER_P:
			pcFrameType = DATA;
			receivedData = LOWER_P;
			break;
		case UPPER_P:
			pcFrameType = DATA;
			receivedData = UPPER_P;
			break;
		case LOWER_I:
			pcFrameType = DATA;
			receivedData = LOWER_I;
			break;
		case UPPER_I:
			pcFrameType = DATA;
			receivedData = UPPER_I;
			break;
		case LOWER_D:
			pcFrameType = DATA;
			receivedData = LOWER_D;
			break;
		case UPPER_D:
			pcFrameType = DATA;
			receivedData = UPPER_D;
			break;
		case P_SETTINGS:
			pcFrameType = DATA;
			receivedData = P_SETTINGS;
			break;
		case I_SETTINGS:
			pcFrameType = DATA;
			receivedData = I_SETTINGS;
			break;
		case D_SETTINGS:
			pcFrameType = DATA;
			receivedData = D_SETTINGS;
			break;
		case STATUS_PC:
			break;
		case ERROR_PC:
			break;
		default:
			break;
	}
}

void solvePCData(char data){
	frame[shiftedIndex] = data;
	shiftedIndex++;
	if(shiftedIndex == 4) {
		shiftedIndex = 0;
		pcFrameType = HEADER;
		saveDataInProperVariable(atof(frame));
	}
}

void saveDataInProperVariable(float value) {
	switch(receivedData) {
			case LOWER_P:
				lowerP = value;
				break;
			case UPPER_P:
				upperP = value;
				break;
			case LOWER_I:
				lowerI = value;
				break;
			case UPPER_I:
				upperI = value;
				break;
			case LOWER_D:
				lowerD = value;
				break;
			case UPPER_D:
				upperD = value;
				break;
			case P_SETTINGS:
				P = value;
				break;
			case I_SETTINGS:
				I = value;
				break;
			case D_SETTINGS:
				D = value;
				break;
			default:
				break;
		}
}

void sendAllDataToPC() {
	//k¹ty
	USART_put_char(PC, ANGLE_DRONE);
	USART_put_float(PC, angleDrone);
	USART_put_char(PC, ANGLE_ENC);
	USART_put_float(PC, angleEncoder);
	USART_put_char(PC, ANGLE_SET);
	USART_put_float(PC, angleSet);
	//parametry pid
	USART_put_char(PC, CURRENT_P);
	USART_put_float(PC, P);
	USART_put_char(PC, CURRENT_I);
	USART_put_float(PC, I);
	USART_put_char(PC, CURRENT_D);
	USART_put_float(PC, D);
	//czas
	USART_put_char(PC, TIME);
	USART_put_long(PC, time);
}

void solveDroneRequest(char data) {

}

void solveEncoderRequest(char data) {

}

char translateFromGrayToBinary(char data) {
	char help;
	char converted = data & 0x80;

	help = converted>>1;
	converted = converted | (help ^ (data & 0x40));
	help = (converted & 0x40)>>1;
	converted = converted | (help ^ (data & 0x20));
	help = (converted & 0x20)>>1;
	converted = converted | (help ^ (data & 0x10));
	help = (converted & 0x10)>>1;
	converted = converted | (help ^ (data & 0x08));
	help = (converted & 0x08)>>1;
	converted = converted | (help ^ (data & 0x04));
	help = (converted & 0x04)>>1;
	converted = converted | (help ^ (data & 0x02));
	help = (converted & 0x02)>>1;
	converted = converted | (help ^ (data & 0x01));

	return converted;
}
