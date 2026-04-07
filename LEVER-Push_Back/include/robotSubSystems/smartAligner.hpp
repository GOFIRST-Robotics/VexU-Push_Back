#pragma once
#include "main.h"


extern bool useSmartAligner;
extern pros::adi::DigitalIn smartAligner;

bool isAligned();
bool moveToAlignerReset(int x, int y, int resetX, int resetY, int resetAngle, int timeout);