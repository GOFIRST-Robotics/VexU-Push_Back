#include "main.h"
#include <tuple>


pros::Motor leverMotorLeft(-6, pros::MotorGearset::green);
pros::Motor leverMotorRight(7, pros::MotorGearset::green);

int useLeftMotor = 1;   // first: temp disconnect, second: perma disable
int useRightMotor = 1;   // first: temp disconnect, second: perma disable

int leverTarget = 0;

void initLever() {
    leverMotorLeft.tare_position();
    leverMotorRight.tare_position();
    pros::delay(25);


    pros::Task leverDriver{[=] {
        while(true) {
            moveLever(leverTarget);
            pros::delay(10);
            pros::lcd::set_text(5, std::to_string(getLeverPosition()) + ", " + std::to_string(leverMotorLeft.get_position()) + ", " + std::to_string(leverMotorRight.get_position()));
        }
    }};
}

int getLeverPosition() {
    int leftMotorPos = leverMotorLeft.get_position();
    int rightMotorPos = leverMotorRight.get_position();


    if (useLeftMotor == 0 || leftMotorPos > 720 || leftMotorPos < -90) {
        leftMotorPos = 0;
        useLeftMotor = 0;
    }

    if (useRightMotor == 0 || rightMotorPos > 720 || rightMotorPos < -90) {
        rightMotorPos = 0;
        useRightMotor = 0;
    }

    int avg = (leftMotorPos + rightMotorPos) / (useLeftMotor + useRightMotor);
    return avg;
}



const int leverMaxAngle = 360;
const int leverMinAngle = 0;



void moveLever(int target) {
    if (target > leverMaxAngle) {target = leverMaxAngle;}
    else if (target < leverMinAngle) {target = leverMinAngle;}

    int pos = getLeverPosition();
    float power = 0;
    float kP = 0.002;

    power = kP * (target - pos);
    leverMotorLeft.move_voltage(12000 * power);
    leverMotorRight.move_voltage(12000 * power);
}


void leverUp() {
    leverTarget = leverMaxAngle;
}

void leverDown() {
    leverTarget = leverMinAngle;
}

void leverUpBlocking() {
    leverTarget = leverMaxAngle;
    int startTime = pros::millis();
    while ((abs(leverTarget - getLeverPosition()) > 25) && (pros::millis() < startTime + 2000)) {
        pros::delay(10);
    }
    leverTarget = leverMinAngle;
}


void leverScoreAmount(int blocks) {
    if (blocks < 1) {blocks = 1;}
    if (blocks > 6) {blocks = 6;}
    leverTarget = (leverMaxAngle/6) * blocks;
    int startTime = pros::millis();
    while ((abs(leverTarget - getLeverPosition()) > 25) && (pros::millis() < startTime + 2000)) {
        pros::delay(10);
    }
    leverTarget = leverMinAngle;
}