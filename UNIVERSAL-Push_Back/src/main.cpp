#include "main.h"
#include "lemlib/api.hpp"

//BeamBreak
pros::adi::DigitalIn BeamBreak('C');
void BeamBreak() {
    return BeamBreak.get_value();
}


//ADI Inputs
pros::adi::DigitalIn robotSelect('A');
int robotVar = 1; // 1 noah 2 aaron
int maxAutos = 2;

// Tasks
void printOdom() {
    pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    pros::delay(50);
}



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    pros::delay(250);
    
    
    //Setting robot
    if (robotSelect.get_value()) {robotVar = 2;}   // Tag in 15in bot


    // Validate driver
    if (robotVar == 0) {   // Daniel
        controller.print(0,0,"Welcome, Fuckass");
        driverDANIEL();
    }

    else if (robotVar == 1) {   // Noah
        controller.print(0,0,"Welcome, Noah");
        driverNOAH();
    }

    else if (robotVar == 2) {   // Aaron
        controller.print(0,0,"Welcome, Aaron");
        driverAARON();
    }
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

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
    if (autonSelectButton.get_value()) {    // Skills starts with button pressed
        selectedAuto = 100; // SKILLS
            switch(robotVar) {
                case 1: // 24in RIGHT
                    pros::lcd::set_text(0, "24in SKILLS");
                    break;
                case 2: // 15in LEFT
                    pros::lcd::set_text(0, "15in SKILLS");
                    break;
            }
    }

    else {  // Normal select
        while(true) {
            selector(maxAutos);
                switch(robotVar) {
                    case 1: // 24in RIGHT
                        if (selectedAuto == 0) {pros::lcd::set_text(0, "24in QUALIFICATION");}
                        if (selectedAuto == 1) {pros::lcd::set_text(0, "24in ELIMINATION");}
                        break;
                    case 2: // 15in LEFT
                        if (selectedAuto == 0) {pros::lcd::set_text(0, "15in QUALIFICATION");}
                        if (selectedAuto == 1) {pros::lcd::set_text(0, "15in ELIMINATION");}
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
    pros::Task printOdomTask(printOdom);

    switch(robotVar) {
        case 1: // 24in RIGHT
            if (selectedAuto == 100) {} // SKILLS
            if (selectedAuto == 0) {rightQuals();}
            if (selectedAuto == 1) {rightElims();}
            break;
        case 2: // 15in LEFT
            if (selectedAuto == 100) {} // SKILLS
            if (selectedAuto == 0) {leftQuals();}
            if (selectedAuto == 1) {rightElims();}
            break;
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
    //pros::Task colorSortTask(colorSort);

}


