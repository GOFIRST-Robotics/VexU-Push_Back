#include "main.h"
#include "lemlib/api.hpp"
#include <iostream>
#include <tuple>
#include <list>
#include <string>

//User Variables
int maxAutos = 4;


//ADI Inputs
pros::adi::DigitalIn robotSelectPort('A');
int robotVar = 2; // 1 noah 2 aaron



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    pros::lcd::set_text(4, "Initialize");
    chassis.calibrate(); // calibrate sensors
    pros::delay(250);
    
    
    //Setting robot
    if (robotSelectPort.get_value()) {robotVar = 1;}   // Tag in 15in bot


    //Driver confirmation
    if (robotVar == 0) {   // Daniel
        controller.print(0,0,"Welcome, Fuckass");
    }
    else if (robotVar == 1) {   // Aaron
        controller.print(0,0,"Welcome, Aaron");
        intakeReverseVar = -1;
    }
    else if (robotVar == 2) {   // Noah
        controller.print(0,0,"Welcome, Noah");
    }
    pros::delay(750);  //Block to confirm driver
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
    pros::lcd::set_text(4, "Disabled");
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
    pros::lcd::set_text(4, "Competition Initialize");
    if (autonSelectButton.get_value()) {    // Skills starts with button pressed
        selectedAuto = 100; // SKILLS
        switch(robotVar) {
            case 1: // 15in LEFT
                printToBoth("15in SKILLS");
                break;
            case 2: // 24in RIGHT
                printToBoth("24in SKILLS");
                break;
        }
    }

    else {  // Normal select
        while(true) {
            selector(maxAutos+1);
            switch(robotVar) {
                case 1: // 15in LEFT
                    if (selectedAuto == 0) {printToBoth("DO NOTHING");}
                    else if (selectedAuto == 1) {printToBoth("15in SAFE STAY");}
                    else if (selectedAuto == 2) {printToBoth("15in SAFE WING");}
                    else if (selectedAuto == 3) {printToBoth("15in GOALRUSH STAY");}
                    else if (selectedAuto == 4) {printToBoth("15in GOALRUSH WING");}
                    else {printToBoth("Unknown Auto");}
                    break;
                case 2: // 24in RIGHT
                    if (selectedAuto == 0) {printToBoth("DO NOTHING");}
                    else if (selectedAuto == 1) {printToBoth("24in SAFE STAY");}
                    else if (selectedAuto == 2) {printToBoth("24in SAFE WING");}
                    else if (selectedAuto == 3) {printToBoth("24in MixUp STAY");}
                    else if (selectedAuto == 4) {printToBoth("24in MixUp WING");}
                    else {printToBoth("Unknown Auto");}
                    break;
            }
            pros::delay(10);
        }
    }
}


/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    pros::lcd::set_text(4, "Autonomous");
    controller.clear_line(0);
    drakeUP();

    if (selectedAuto == 100) {  //Skills
        switch(robotVar) {
            case 1: // 15in LEFT
                leftSKILLS();
                break;
            case 2: // 24in RIGHT
                rightSKILLS();
                break;
        }
    }
    else {  //Match autos
        switch(robotVar) {
            case 1: // 15in LEFT
                if (selectedAuto == 0) {}
                else if (selectedAuto == 1) {leftSafeSTAY();}
                else if (selectedAuto == 2) {leftSafeWING();}
                else if (selectedAuto == 3) {leftGoalRushSTAY();}
                else if (selectedAuto == 4) {leftGoalRushWING();}
                break;
            case 2: // 24in RIGHT
                if (selectedAuto == 0) {}
                else if (selectedAuto == 1) {rightSafeSTAY();}
                else if (selectedAuto == 2) {rightSafeWING();}
                else if (selectedAuto == 3) {rightMixUpSTAY();}
                else if (selectedAuto == 4) {rightMixUpWING();}
                break;
        }
    }
}


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    pros::lcd::set_text(4, "opControl");
    if (robotVar == 0) {driverDANIEL();}   // Daniel
    else if (robotVar == 1) {driverAARON();}   // Noah
    else if (robotVar == 2) {driverNOAH();}   // Aaron
}


void opcontrol1() {
    rightSafeWING();







    while(true) {
        pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
        pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
        pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
        pros::delay(50);
    }
    pros::delay(50);

}
