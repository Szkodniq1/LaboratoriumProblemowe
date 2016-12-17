#ifndef __SOLVER_H
#define __SOLVER_H

#define TOMKOWA_BIBLIOTEKA 0
#define KUKSOWO_LASAKOWA_BIBLOTEKA 1

//ustawiona biblioteka
#define SET_LIBRARY TOMKOWA_BIBLIOTEKA

//Estimated params
float P,I,D;
//Angles
float angleDrone,angleEncoder,angleSet;
//Bounds
float lowerP,upperP,lowerI,upperI,lowerD,upperD;

void initSolver();
void solveRegulatorParams();

#endif
