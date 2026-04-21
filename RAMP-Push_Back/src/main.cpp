#include "main.h"
#include "lemlib/api.hpp"
#include <iostream>
#include <tuple>
#include <list>
#include <string>


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    pros::lcd::set_text(0, "Initialize");
    chassis.calibrate(); // calibrate sensors
    pros::delay(250);
    initSelector(8, 8); //Initalize seleector with default auto and amount of autos
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
    pros::lcd::set_text(0, "Competition Initialize");
    
    while(true) {
        timerSelect();
        selector();
        if (getSelectedAuto() == 0) {printToBoth("DO NOTHING");}
        else if (getSelectedAuto() == 1) {printToBoth("Ramp STANDARD WING");}
        else if (getSelectedAuto() == 2) {printToBoth("Ramp STANDARD WING + DISRUPT");}
        else if (getSelectedAuto() == 3) {printToBoth("Ramp STANDARD DISRUPT");}

        else if (getSelectedAuto() == 4) {printToBoth("Ramp 4Low 6 Long WING");}
        else if (getSelectedAuto() == 5) {printToBoth("Ramp 4Low 6 Long WING + DISRUPT");}
        else if (getSelectedAuto() == 6) {printToBoth("Ramp 4Low 6 Long DISRUPT");}

        else if (getSelectedAuto() == 7) {printToBoth("Ramp Elims WING");}
        else if (getSelectedAuto() == 8) {printToBoth("Ramp Elims WING + DISRUPT");}
        else {printToBoth("Unknown Auto");}
    }
    pros::delay(10);
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
    pros::lcd::set_text(0, "Autonomous");
    controller.clear_line(0);
    startTimer();
    drakeUP();

    if (getSelectedAuto() == 0) {}
    else if (getSelectedAuto() == 1) {leftStandardWing();}
    else if (getSelectedAuto() == 2) {leftStandardWingDisrupt();}
    else if (getSelectedAuto() == 3) {leftStandardDisrupt();}

    else if (getSelectedAuto() == 4) {leftFourLowSixLongWing();}
    else if (getSelectedAuto() == 5) {leftFourLowSixLongWingDisrupt();}
    else if (getSelectedAuto() == 6) {leftFourLowSixLongDisrupt();}

    else if (getSelectedAuto() == 7) {leftElimsWing();}
    else if (getSelectedAuto() == 8) {leftElimsWingDisrupt();}
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
    driverAARON();

    //autonomous();
}
