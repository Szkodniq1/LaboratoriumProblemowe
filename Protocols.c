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

}

void solveDroneRequest(char data) {

}
void solveEncoderRequest(char data) {

}
