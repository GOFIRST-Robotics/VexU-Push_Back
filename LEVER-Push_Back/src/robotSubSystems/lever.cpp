#include "main.h"
#include <tuple>
///////////////////////////////12

pros::Motor leverMotorLeft(-4, pros::MotorGearset::green);
pros::Motor leverMotorRight(5, pros::MotorGearset::green);
pros::Rotation leverEncoder(12);

int useLeftMotor = 1;   // first: temp disconnect, second: perma disable
int useRightMotor = 1;   // first: temp disconnect, second: perma disable

int leverTarget = 178;

void initLever() {
    leverMotorLeft.tare_position();
    leverMotorRight.tare_position();
    pros::delay(25);


    pros::Task leverDriver{[=] {    //Lambda Task, acts at the "motor" for the lever
        while(true) {
            moveLever(leverTarget);
            pros::delay(10);
           // pros::lcd::set_text(5, "Lever Pos: " + std::to_string(getLeverPosition()) + ", 4bar: " + std::to_string((int) fourBarPiston.is_extended()) + ", Target:" + std::to_string(leverTarget));
        }
    }};
}

int getLeverPositionMOTORS() {
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

int getLeverPosition() {
    return leverEncoder.get_angle()/100;
}



const int leverMaxAngleUP = 300;
const int leverMaxAngleDOWN = 310;//313;
const int leverMinAngle = 178;


//int antiBeater = 0;
void moveLever(int target) {
    if (target > leverMaxAngleDOWN) {target = leverMaxAngleDOWN;}
    else if (target < leverMinAngle) {target = leverMinAngle;}

    int pos = getLeverPosition();
    float power = 0;
    float kP = 0.005;

    int error = (target - pos);



    power = kP * error;
    if (target > 280) {power = 1;}
    if ((target > 280) && (abs(target - pos) < 15)) {power *= 0.01;}

    

    if (!fourBarPiston.is_extended()) {
        int voltageMod = 1;
        if (target < 200) {voltageMod = 2;}
        leverMotorLeft.move_voltage(5000 * voltageMod * power);
        leverMotorRight.move_voltage(5000 * voltageMod * power);
    }
    else {
        
        leverMotorLeft.move_voltage(12000 * power);
        leverMotorRight.move_voltage(12000 * power);
    }
}


void leverUp() {
    if (fourBarPiston.is_extended()) {
        leverTarget = leverMaxAngleUP;
    }
    else {leverTarget = leverMaxAngleDOWN;}
}

void leverDown() {leverTarget = leverMinAngle;}




//Autonomous Shortcuts
void leverUpBlocking() {
    backFlapOPEN();
    pros::delay(150);
    leverUp();
    int startTime = pros::millis();
    while ((abs(leverTarget - getLeverPosition()) > 25) && (pros::millis() < startTime + 1000)) {
        pros::delay(10);
    }
    leverDown();
}


void leverScoreAmountBlocking(int blocks) {
    backFlapOPEN();
    pros::delay(150);
    if (blocks < 1) {blocks = 1;}
    if (blocks > 6) {blocks = 6;}
    leverTarget = (leverMaxAngleUP/6) * blocks;
    int startTime = pros::millis();
    while ((abs(leverTarget - getLeverPosition()) > 25) && (pros::millis() < startTime + 1000)) {
        pros::delay(10);
    }
    leverTarget = leverMinAngle;
    pros::delay(250);
    backFlapCLOSE();
}


void leverSetCustomTarget(int target) {
    backFlapOPEN();
    pros::delay(150);
    leverTarget = target;
    int startTime = pros::millis();
    while ((abs(leverTarget - getLeverPosition()) > 25) && (pros::millis() < startTime + 1000)) {
        pros::delay(10);
    }
}