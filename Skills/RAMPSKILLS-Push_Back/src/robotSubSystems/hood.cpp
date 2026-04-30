#include "main.h"

pros::adi::Pneumatics hoodPiston('F', false);

// Hood Shortcuts
void hoodDOWN() {
    hoodPiston.set_value(false);
}

void hoodUP() {
    hoodPiston.set_value(true);
}