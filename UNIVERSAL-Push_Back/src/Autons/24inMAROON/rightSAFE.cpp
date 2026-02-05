#include "main.h"

void rightSafeMAIN() {
    chassis.setPose(24.5,57.5,90);
    chassis.moveToPoint(55,55,1000, {.maxSpeed = 100});  //Align to mid goal

    chassis.swingToPoint(61,61, DriveSide::LEFT, 1000, {.maxSpeed = 60}, false);  //move to mid goal
    intakeOutSLOW();
    pros::delay(3000);

    chassis.moveToPoint(28,24,3000, {.forwards = false});  //Long movement to middle goal
    chassis.waitUntilDone();
    pros::delay(250);

    chassis.turnToHeading(cardinalWEST, 500); //Turn to match loader
    scraperDOWN();
    intakeInFAST();
    chassis.moveToPoint(7,24,2000, {.maxSpeed = 75});  //Matchload 1
    chassis.waitUntilDone();
    pros::delay(700);
    intakeSTOP();


    //--Half Measure--//
    chassis.moveToPoint(24,24,1500, {.forwards = false, .maxSpeed = 90});   //Half Measure
    chassis.turnToHeading(cardinalSOUTHWEST, 500);   //Remove bad
    chassis.waitUntilDone();
    scraperUP();
    intakeOutFAST();
    pros::delay(300);
    intakeSTOP();
    chassis.turnToHeading(cardinalWEST, 500);    //Turn to goal
    //--End half measure--//


    chassis.moveToPoint(50,23,2000, {.forwards = false, .maxSpeed = 90});   //Long goal
    chassis.waitUntilDone();
    intakeScore();
    scraperDOWN();
    pros::delay(2500);

    chassis.moveToPoint(7,24,1500, {.maxSpeed = 75});  //Matchload 2
    intakeInFAST();
    chassis.waitUntilDone();
    pros::delay(3000);
    intakeSTOP();

    chassis.moveToPoint(51,23,2000, {.forwards = false, .maxSpeed = 90});   //Long goal 2
    chassis.waitUntilDone();
    intakeScore();
    pros::delay(2500);
    scraperUP();

}


void rightSafeSTAY() {
    rightSafeMAIN();
    chassis.moveToPoint(51,23,10000, {.forwards = false, .maxSpeed = 90});   //Long goal 2
}

void rightSafeWING() {
    rightSafeMAIN();
    
    chassis.moveToPoint(30,37,1000, {.maxSpeed = 60});  //move away from goal
    chassis.turnToHeading(cardinalWEST, 1000);
    chassis.moveToPoint(60,36,1000, {.forwards = false, .maxSpeed = 60});   //descore arm
    chassis.waitUntil(15);
    drakeDOWN();
}