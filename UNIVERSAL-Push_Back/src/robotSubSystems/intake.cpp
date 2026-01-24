#include "main.h"


// Autonomous Intake Shortcuts
void intakeInFAST(){
    mainIntake.move_voltage(12000);
    indexerIntake.move_voltage(12000);
    scoringIntake.move_voltage(0);
}

void intakeInSLOW(){
    mainIntake.move_voltage(8000);
    indexerIntake.move_voltage(8000);
    scoringIntake.move_voltage(0);
}

void intakeOutFAST(){
    mainIntake.move_voltage(-12000);
    indexerIntake.move_voltage(-12000);
    scoringIntake.move_voltage(-12000);
}

void intakeOutSLOW(){
    mainIntake.move_voltage(-8000);
    indexerIntake.move_voltage(-8000);
    scoringIntake.move_voltage(-8000);
}

void intakeCustomSpeed(int multiplier){
    mainIntake.move_voltage(12000 * multiplier);
}

void intakeScore() {
    mainIntake.move_voltage(12000);
    indexerIntake.move_voltage(12000);
    scoringIntake.move_voltage(12000);
}

void intakeSTOP() {
    mainIntake.move_voltage(0);
    indexerIntake.move_voltage(0);
    scoringIntake.move_voltage(0);
}