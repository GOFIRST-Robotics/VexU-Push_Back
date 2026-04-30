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
    initSelector(1, 11); //Initalize selector with default auto and amount of autos
    initLever();

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
    pros::lcd::set_text(0, "Disabled");
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
    pros::lcd::set_text(7, "==== Auto ======= Action =====================");

    while(true) {
        timerSelect();
        selector();
        if (getSelectedAuto() == 0) {printToBoth("DO NOTHING");}
        else if (getSelectedAuto() == 1) {printToBoth("Lever STANDARD WING");}
        else if (getSelectedAuto() == 2) {printToBoth("Lever STANDARD WING DISRUPT");}
        else if (getSelectedAuto() == 3) {printToBoth("Lever STANDARD DISRUPT");}

        else if (getSelectedAuto() == 4) {printToBoth("Lever 4Low 6 Long WING");}
        else if (getSelectedAuto() == 5) {printToBoth("Lever 4Low 6 Long WING + DISRUPT");}
        else if (getSelectedAuto() == 6) {printToBoth("Lever 4Low 6 Long DISRUPT");}

        else if (getSelectedAuto() == 7) {printToBoth("Lever GREED WING");}
        else if (getSelectedAuto() == 8) {printToBoth("Lever GREED WING + DISRUPT");}
        else if (getSelectedAuto() == 9) {printToBoth("Lever GREED DISRUPT");}

        else if (getSelectedAuto() == 10) {printToBoth("Lever Elims WING");}
        else if (getSelectedAuto() == 11) {printToBoth("Lever Elims WING + DISRUPT");}



        else {printToBoth("Unknown Auto");}
        pros::delay(10);
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
    pros::lcd::set_text(0, "Autonomous");
    controller.clear_line(0);
chassis.setPose(24,88,cardinalSOUTH);
intakeInFAST();
pros::delay(500);
drakeUP();
fourBarUP();


chassis.moveToPoint(24, 120, 1000, {.forwards = false, .maxSpeed = 80});

pros::delay(150);
intakeSTOP();
chassis.turnToHeading(cardinalWEST, 1000);

chassis.moveToPoint(50, 120.5, 1500, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal 1
scraperDOWN();
chassis.tank(-50, -50);
pros::delay(350);
chassis.tank(0, 0);
pros::delay(350);
chassis.setPose(42,120,cardinalWEST);
    leverUpBlocking();
    pros::delay(75);
    leverUpBlocking();
    intakeOutFAST();
pros::delay(350);

intakeInFAST();


///////////////////////////////////////////////////////////////////////////////////////////////////////////PHASE 1 COMPLETE



chassis.moveToPoint(20,120, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
backFlapCLOSE();
chassis.moveToPoint(5, 120, 2000, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 1
intakeSTOP();

chassis.moveToPoint(24, 120, 2000, {.forwards = false, .maxSpeed = 70}, false); //Back away         ######was 120
chassis.turnToHeading(cardinalNORTH, 750, {}, false);
scraperUP();
pros::delay(500);
chassis.moveToPoint(24, 135, 2000, {.maxSpeed = 50}); //Pick up wall blocks
intakeInFAST();
chassis.waitUntilDone();
pros::delay(350);

chassis.moveToPoint(24, 133, 2000, {.forwards = false, .maxSpeed = 70}, false); //Cross position
chassis.turnToHeading(cardinalEAST, 750);

chassis.moveToPoint(115, 134, 5000, {.maxSpeed = 80}, false); //Cross long
chassis.turnToHeading(cardinalSOUTH, 750);



chassis.moveToPoint(115, 121.5, 4000, {.maxSpeed = 80}, false); //Align to goal
chassis.turnToHeading(cardinalEAST, 750);
scraperDOWN();


chassis.moveToPoint(80, 122.5, 2000, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal 2

chassis.tank(-50, -50);
pros::delay(350);
chassis.tank(0, 0);
pros::delay(350);
chassis.setPose(102,120,cardinalEAST);
pros::delay(100);
    leverUpBlocking();
    pros::delay(75);
    leverUpBlocking();
    intakeOutFAST();
pros::delay(300);
intakeInFAST();
////////////////////////////////////////////////////////////////////////////////////////////////PHASE 2 COMPLETE
chassis.moveToPoint(120,119, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 2
chassis.turnToHeading(cardinalEAST, 500, {.earlyExitRange = 2});
backFlapCLOSE();
chassis.moveToPoint(140, 119, 2500, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 2
intakeSTOP();

chassis.moveToPoint(90, 120, 2000, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal 3
scraperUP();
    leverUpBlocking();
    pros::delay(75);
    leverUpBlocking();
    intakeOutFAST();
pros::delay(300);
intakeInFAST();

chassis.moveToPoint(112, 73, 2000, {.maxSpeed = 80});   //Align to scrape
intakeSTOP();

chassis.turnToHeading(cardinalEAST, 750);
backFlapCLOSE();
chassis.moveToPoint(122, 73, 1000, {.maxSpeed = 50}, false);    //Scrape
chassis.moveToPoint(125, 73, 500, {.maxSpeed = 20}, false);    //Scrape

scraperDOWN();
pros::delay(750);
////Wiggle
chassis.turnToHeading(cardinalEAST+20, 350, {.earlyExitRange = 0});
chassis.turnToHeading(cardinalEAST-20, 350, {.earlyExitRange = 0});
chassis.turnToHeading(cardinalEAST+30, 350, {.earlyExitRange = 0});
chassis.turnToHeading(cardinalEAST-30, 350, {.earlyExitRange = 0});
intakeInSLOW();
chassis.moveToPoint(115, 73, 750, {.forwards = false, .maxSpeed = 60}, false);    //Scrape
///Jiggle

chassis.turnToHeading(cardinalNORTHWEST-10, 1000, {.maxSpeed = 50});    //Turn to randoms

chassis.moveToPoint(90, 100, 3000, {.maxSpeed = 80});    //Randoms
intakeInFAST();
pros::delay(250);
scraperUP();
chassis.moveToPoint(75, 100, 3000, {.maxSpeed = 50}, false);    //Randoms


chassis.moveToPoint(88,90, 2000, {.forwards = false, .maxSpeed = 80});    //Randoms back away
scraperDOWN();
chassis.waitUntilDone();
scraperUP();
pros::delay(1000);
chassis.turnToHeading(cardinalSOUTHWEST, 750, {}, false);   //Turn to low goal
intakeInSLOW();

chassis.moveToPoint(85, 83, 1000, {.maxSpeed = 60}, false); //Low goal
chassis.turnToHeading(cardinalSOUTHWEST+20, 500, {},  false);
intakeOutSLOW();
pros::delay(1500);
intakeInFAST();
pros::delay(550);
intakeOutSLOW();
pros::delay(500);

chassis.moveToPoint(95,100, 3000, {.forwards = false, .maxSpeed = 80});    //goal back away
chassis.turnToHeading(cardinalWEST, 750);
intakeInSLOW();
chassis.moveToPoint(11, 100, 2000, {.maxSpeed = 70});   //Move to park position
chassis.turnToHeading(cardinalSOUTH+13, 750);


chassis.moveToPoint(6.5,72,1400, {.maxSpeed = 70});
chassis.waitUntilDone();
chassis.tank(-50, -50); //Full speed back
pros::delay(595);

chassis.tank(10, 10); //Stop once tilting to correct angle
pros::delay(100);
chassis.tank(0, 0); //Stop once tilting to correct angle


    while(true) {
        pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
        pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
        pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
        pros::delay(50);
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
    pros::lcd::set_text(0, "opControl");
    driverNOAH();



}