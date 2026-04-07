#include "main.h"


bool useSmartAligner = true;
pros::adi::DigitalIn smartAligner('D');

bool isAligned() {
    return smartAligner.get_value();
}

bool moveToAlignerReset(int x, int y, int resetX, int resetY, int resetAngle, int timeout) {
    chassis.moveToPoint(x, y, timeout, {.forwards = false, .maxSpeed = 80});
    pros::delay(100);
    while (chassis.isInMotion() && !isAligned()) {
        pros::delay(10);
    }
    chassis.cancelMotion();
    chassis.tank(-60, -60);
    pros::delay(150);
    chassis.setPose(resetX, resetY, resetAngle);
    pros::delay(50);
    chassis.tank(0,0);
    return isAligned();
}