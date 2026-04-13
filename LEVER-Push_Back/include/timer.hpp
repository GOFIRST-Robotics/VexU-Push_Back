#pragma once
#include "main.h"

extern pros::adi::DigitalIn timerSelectButton;

void startTimer();
void waitUntilTime();
void waitUntilHardcodeTime(uint32_t time);
void timerSelect();