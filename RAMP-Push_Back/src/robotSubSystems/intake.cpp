#include "main.h"


pros::Motor frontIntake(-11, pros::MotorGearset::blue);
pros::MotorGroup midIntake({18, 19}, pros::MotorGearset::blue);
pros::Motor scoringIntake(-12, pros::MotorGearset::blue);


bool useBeamBreak = true;
// Intake Beam Break
pros::adi::DigitalIn beamBreak('D');

bool isBlockPresent() {   //True is has block, false is no block. Requires invert
    return beamBreak.get_value();   //High is unbroken, no block. Low is broken, block
}

bool holdUntilBlockPresent(uint32_t timeout, uint32_t minTime, bool useBeamBreak) {
    uint32_t startTime = pros::millis();

    while((pros::millis() - startTime < timeout)){ //Wait while no block and within timeout
        uint32_t elapsedTime = pros::millis() - startTime;
        if (useBeamBreak && elapsedTime >= minTime && isBlockPresent()) {
            return true; //Exit early if block present
        }
        pros::delay(10);
    }
    return !useBeamBreak;   // If beam break is used and no block, return False. If beam break not used, wait for timeout and return True
}

bool holdUntilBlockRemoved(uint32_t timeout, uint32_t minTime, bool useBeamBreak) {
    uint32_t startTime = pros::millis();

    while((pros::millis() - startTime < timeout)) { //Wait until timeout
        uint32_t elapsedTime = pros::millis() - startTime;
        if (useBeamBreak && elapsedTime >= minTime && !isBlockPresent()) {
            pros::delay(250);
            if (!isBlockPresent()) {
                pros::delay(250);
                if (!isBlockPresent()) {
                    pros::delay(350);
                    return true; //Exit early if no block for 250ms
                }
            }
        }
        pros::delay(10);
    }
    return !useBeamBreak;   // If beam break is used and no block, return False. If beam break not used, wait for timeout and return True
}


// Autonomous Intake Shortcuts
void intakeInFAST(){
    frontIntake.move_voltage(12000);
    midIntake.move_voltage(12000);
    scoringIntake.move_voltage(-4000);
}

void intakeInSLOW(){
    frontIntake.move_voltage(8000);
    midIntake.move_voltage(8000);
    scoringIntake.move_voltage(-4000);
}

void intakeOutFAST(){
    frontIntake.move_voltage(-12000);
    midIntake.move_voltage(-12000);
    scoringIntake.move_voltage(-12000);
}

void intakeOutSLOW(){
    frontIntake.move_voltage(-6000);
    midIntake.move_voltage(-8000);
    scoringIntake.move_voltage(-8000);
}

void intakeOutSuperSLOW(){
    frontIntake.move_voltage(-4000);
    midIntake.move_voltage(-6000);
    scoringIntake.move_voltage(-8000);
}

void intakeCustomSpeed(int multiplier){
    frontIntake.move_voltage(12000 * multiplier);
    midIntake.move_voltage(12000 * multiplier);
}

void intakeScore() {
    frontIntake.move_voltage(12000);
    midIntake.move_voltage(12000);
    scoringIntake.move_voltage(12000);
}

void intakeScoreSLOW() {
    frontIntake.move_voltage(12000);
    midIntake.move_voltage(12000);
    scoringIntake.move_voltage(9000);
}

void intakeSTOP() {
    frontIntake.move_voltage(0);
    midIntake.move_voltage(0);
    scoringIntake.move_voltage(-4000);
}

void intakeFULLSTOP() {
    frontIntake.move_voltage(0);
    midIntake.move_voltage(0);
    scoringIntake.move_voltage(0);
}

void intakeInFIRSTSTAGE(int multiplier) {
    frontIntake.move_voltage(12000 * multiplier);
}