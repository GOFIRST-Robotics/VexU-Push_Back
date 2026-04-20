#include "main.h"

#define UP true
#define DOWN false

static bool fourBarState;

pros::adi::Pneumatics fourBarPiston('G', false);
pros::adi::Pneumatics backFlapPiston('G', false);

// Four Bar Shortcuts
void fourBarUP() {
    fourBarPiston.set_value(true);
    fourBarState = UP;
}

void fourBarDOWN() {
    fourBarPiston.set_value(false);
    fourBarState = DOWN;
}

bool getFourBarState() {
    return fourBarState;
}


void backFlapOPEN() {
    backFlapPiston.set_value(true);
}

void backFlapCLOSE() {
    backFlapPiston.set_value(false);
}