#include "main.h"


pros::MotorGroup intakeMain({-13, 14}, pros::MotorGearset::blue); //Front and color sort


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
    intakeMain.move_voltage(12000);
}

void intakeInSLOW(){
    intakeMain.move_voltage(8000);
}

void intakeOutFAST(){
    intakeMain.move_voltage(-12000);
}

void intakeOutSLOW(){
    intakeMain.move_voltage(-8000);
}

void intakeOutSuperSLOW(){
    intakeMain.move_voltage(-6800);
}

void intakeCustomSpeed(int multiplier){
    intakeMain.move_voltage(12000 * multiplier);
}

void intakeSTOP() {
    intakeMain.move_voltage(0);
}


