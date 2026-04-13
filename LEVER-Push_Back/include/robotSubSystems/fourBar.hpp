#pragma once
#include "main.h"


extern pros::adi::Pneumatics fourBarPiston;
extern pros::adi::Pneumatics backFlapPiston;

// Four Bar Shortcuts
void fourBarUP(void);
void fourBarDOWN(void);

void backFlapOPEN(void);
void backFlapCLOSE(void);