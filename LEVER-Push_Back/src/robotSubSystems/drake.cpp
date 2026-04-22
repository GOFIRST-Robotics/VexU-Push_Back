#include "main.h"


pros::adi::Pneumatics DrakePiston('G', false);
//NOTE: TRUE IS DOWN, FALSE IS UP

// Drake Shortcuts
void drakeDOWN() {
    DrakePiston.retract();
}

void drakeUP() {
    DrakePiston.extend();
}