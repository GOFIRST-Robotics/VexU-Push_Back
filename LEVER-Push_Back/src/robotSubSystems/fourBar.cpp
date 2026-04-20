#include "main.h"


pros::adi::Pneumatics fourBarPiston('F', false);
pros::adi::Pneumatics backFlapPiston('E', false);

// Four Bar Shortcuts
void fourBarUP() {
    fourBarPiston.set_value(true);
}

void fourBarDOWN() {
    fourBarPiston.set_value(false);
}


void backFlapOPEN() {
    backFlapPiston.set_value(true);
}

void backFlapCLOSE() {
    backFlapPiston.set_value(false);
}