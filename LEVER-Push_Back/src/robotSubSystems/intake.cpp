#include "main.h"


pros::MotorGroup frontAndMidIntake({-7, 19}, pros::MotorGearset::blue); //Front and color sort
pros::Motor mainIntake(20, pros::MotorGearset::blue); //Reverse multiplier
pros::Motor scoringIntake(-6, pros::MotorGearset::blue); //Reverse multiplier


bool useBeamBreak = true;

// Intake Beam Break
pros::adi::DigitalIn beamBreak('C');

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
    frontAndMidIntake.move_voltage(12000);
    mainIntake.move_voltage(12000);
    scoringIntake.move_voltage(-4000);
}

void intakeInSLOW(){
    frontAndMidIntake.move_voltage(8000);
    mainIntake.move_voltage(8000);
    scoringIntake.move_voltage(-4000);
}

void intakeOutFAST(){
    frontAndMidIntake.move_voltage(-12000);
    mainIntake.move_voltage(-12000);
    scoringIntake.move_voltage(-12000);
}

void intakeOutSLOW(){
    frontAndMidIntake.move_voltage(-6000);
    mainIntake.move_voltage(-8000);
    scoringIntake.move_voltage(-8000);
}

void intakeOutSuperSLOW(){
    frontAndMidIntake.move_voltage(-4000);
    mainIntake.move_voltage(-6000);
    scoringIntake.move_voltage(-8000);
}

void intakeCustomSpeed(int multiplier){
    frontAndMidIntake.move_voltage(12000 * multiplier);
    mainIntake.move_voltage(12000 * multiplier);
}

void intakeScore() {
    frontAndMidIntake.move_voltage(12000);
    mainIntake.move_voltage(12000);
    scoringIntake.move_voltage(12000);
}

void intakeScoreSLOW() {
    frontAndMidIntake.move_voltage(12000);
    mainIntake.move_voltage(12000);
    scoringIntake.move_voltage(9000);
}

void intakeSTOP() {
    frontAndMidIntake.move_voltage(0);
    mainIntake.move_voltage(0);
    scoringIntake.move_voltage(-4000);
}

void intakeFULLSTOP() {
    frontAndMidIntake.move_voltage(0);
    mainIntake.move_voltage(0);
    scoringIntake.move_voltage(0);
}

void intakeInFIRSTSTAGE(int multiplier) {
    frontAndMidIntake.move_voltage(12000 * multiplier);
}