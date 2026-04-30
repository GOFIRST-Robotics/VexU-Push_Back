#include "main.h"


pros::adi::Pneumatics fourBarPiston('F', false);
pros::adi::Pneumatics backFlapPiston('E', false);

// Four Bar Shortcuts
void fourBarUP() {
    fourBarPiston.extend();
}

void fourBarDOWN() {
    fourBarPiston.retract();
}


void backFlapOPEN() {
    backFlapPiston.extend();
}

void backFlapCLOSE() {
    backFlapPiston.retract();
}