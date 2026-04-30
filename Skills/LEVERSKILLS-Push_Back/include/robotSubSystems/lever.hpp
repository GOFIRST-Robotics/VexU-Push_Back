#pragma once
#include "main.h"


extern pros::Motor leverMotorLeft;
extern pros::Motor leverMotorRight;



void initLever();
int getLeverPosition(void);


void moveLever(int target);

void leverUp(void);
void leverDown(void);

//Autonomous Shortcuts
void leverUpBlocking(void);
void leverScoreAmountBlocking(int blocks);
void leverSetCustomTarget(int target);
