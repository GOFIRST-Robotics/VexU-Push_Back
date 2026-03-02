#pragma once
#include "main.h"

extern bool useBeamBreak;
extern int intakeReverseVar;
// Intake Beam Break
extern pros::adi::DigitalIn beamBreak;
bool isBlockPresent(void);

bool holdUntilBlockPresent(uint32_t timeout = 3000, uint32_t minTime = 500, bool useBeamBreak = true);
bool holdUntilBlockRemoved(uint32_t timeout = 3000, uint32_t minTime = 500, bool useBeamBreak = true);

// Autonomous Intake Shortcuts
void intakeInFAST(void);
void intakeInSLOW(void);
void intakeOutFAST(void);
void intakeOutSLOW(void);
void intakeCustomSpeed(int multiplier);
void intakeScore(void);
void intakeSTOP(void);

void intakeInFIRSTSTAGE(int multiplier);