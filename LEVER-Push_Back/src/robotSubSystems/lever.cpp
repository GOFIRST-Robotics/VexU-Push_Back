#include "main.h"


pros::Motor leverMotorLeft(-6, pros::MotorGearset::green);
pros::Motor leverMotorRight(7, pros::MotorGearset::green);

int useLeftMotor = 1;
int useRightMotor = 1;

void initLever() {
    leverMotorLeft.tare_position();
    leverMotorRight.tare_position();
}

int getLeverPosition() {
    int leftMotorPos = leverMotorLeft.get_position();
    int rightMotorPos = leverMotorRight.get_position();

    if (useLeftMotor == 0 || leftMotorPos > 360 || leftMotorPos < -20) {
        useLeftMotor = 0;
        leftMotorPos = 0;
    }
    if (useRightMotor == 0 || rightMotorPos > 360 || rightMotorPos < -20) {
        useRightMotor = 0;
        rightMotorPos = 0;
    }

    int avg = (leftMotorPos + rightMotorPos) / (useLeftMotor + useRightMotor);
    pros::lcd::set_text(5, std::to_string(avg));
    return avg;
}

