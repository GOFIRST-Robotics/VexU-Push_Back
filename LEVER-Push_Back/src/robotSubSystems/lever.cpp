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


    pros::Task leverDriver{[=] {    //Lambda Task, acts at the "motor" for the lever
        while(true) {
            moveLever(leverTarget);
            pros::delay(10);
            pros::lcd::set_text(5, "Lever Pos: " + std::to_string(getLeverPosition()) + ", L Mot: " + std::to_string((int) leverMotorLeft.get_position()) + ", R Mot: " + std::to_string((int) leverMotorRight.get_position()));
        }
    }};
}

int getLeverPosition() {
    int leftMotorPos = leverMotorLeft.get_position();
    int rightMotorPos = leverMotorRight.get_position();

    //Motors need to be disabled if disconnected to avoid breaking the average position
    if (useLeftMotor == 0 || leftMotorPos > 720 || leftMotorPos < -90) {    //Perma disable motor if disconnected or freespinning
        leftMotorPos = 0;
        useLeftMotor = 0;
    }

    if (useRightMotor == 0 || rightMotorPos > 720 || rightMotorPos < -90) {
        rightMotorPos = 0;
        useRightMotor = 0;
    }

    int avg = (leftMotorPos + rightMotorPos) / (useLeftMotor + useRightMotor);  //Average if both motors working, otherwise only return working motor
    return avg;
}



const int leverMaxAngle = 320;
const int leverMinAngle = 0;


void moveLever(int target, int maxVoltage) {
    if (target > leverMaxAngle) {target = leverMaxAngle;}
    else if (target < leverMinAngle) {target = leverMinAngle;}

    int pos = getLeverPosition();
    float power = 0;
    float kP = 0.01;

    power = kP * (target - pos);
    float outputVoltage = power * 12000;

    // Cap max voltage to given max value
    if (outputVoltage > maxVoltage) {
        outputVoltage = maxVoltage;
    }
    else if (outputVoltage < -maxVoltage) {
        outputVoltage = maxVoltage;
    }

    leverMotorLeft.move_voltage(outputVoltage);
    leverMotorRight.move_voltage(outputVoltage);
}

void moveLever(int target) {
    moveLever(target, 12000);
}


void leverUp() {leverTarget = leverMaxAngle;}

void leverDown() {leverTarget = leverMinAngle;}



//Autonomous Shortcuts
void leverUpBlocking() {
    backFlapOPEN();
    leverTarget = leverMaxAngle;
    int startTime = pros::millis();
    while ((abs(leverTarget - getLeverPosition()) > 25) && (pros::millis() < startTime + 2000)) {
        pros::delay(10);
    }
    leverTarget = leverMinAngle;
    pros::delay(250);
    backFlapCLOSE();
}


void leverScoreAmountBlocking(int blocks) {
    backFlapOPEN();
    if (blocks < 1) {blocks = 1;}
    if (blocks > 6) {blocks = 6;}
    leverTarget = (leverMaxAngle/6) * blocks;
    int startTime = pros::millis();
    while ((abs(leverTarget - getLeverPosition()) > 25) && (pros::millis() < startTime + 2000)) {
        pros::delay(10);
    }
    leverTarget = leverMinAngle;
    pros::delay(250);
    backFlapCLOSE();
}