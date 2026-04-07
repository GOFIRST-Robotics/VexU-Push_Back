#pragma once
#include "main.h"

void printToBoth(const std::string& input);

void printOdom(void);

void debugAuto(void);


extern uint32_t autonStartTime;
extern uint32_t doAtTime;
extern pros::adi::DigitalIn timerSelectButton;
void initTimer();
void waitUntilTime();
void waitUntilTime(uint32_t time);
void timerSelect();