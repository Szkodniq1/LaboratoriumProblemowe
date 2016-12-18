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
			USART_put(PC, START_UC);
			break;
		case STOP_PC:
			STATE = STATE_IDLE;
			USART_put(PC, STOP_UC);
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
	frame[index] = data;
	index++;
	if(index == 4) {
		index = 0;
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
	USART_put(PC, ANGLE_DRONE);
	USART_put_float(PC, angleDrone);
	USART_put(PC, ANGLE_ENC);
	USART_put_float(PC, angleEncoder);
	USART_put(PC, ANGLE_SET);
	USART_put_float(PC, angleSet);
	//parametry pid
	USART_put(PC, CURRENT_P);
	USART_put_float(PC, P);
	USART_put(PC, CURRENT_I);
	USART_put_float(PC, I);
	USART_put(PC, CURRENT_D);
	USART_put_float(PC, D);
	//czas
	USART_put(PC, TIME);
	USART_put_long(PC, time);
}

void solveDroneRequest(char data) {

}
void solveEncoderRequest(char data) {

}
