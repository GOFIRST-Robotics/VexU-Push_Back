#include "main.h"


void leftGoalRushMAIN() {
    chassis.setPose(24.5,87.55,90);

    chassis.moveToPoint(54,92,1000, {.maxSpeed = 100});  //Align to mid goal

    chassis.turnToHeading(cardinalNORTHWEST,750, {.maxSpeed = 80});
    chassis.moveToPoint(61,84,1000, {.forwards = false, .maxSpeed = 85});  //move to mid goal

    chassis.waitUntilDone();
    intakeScore();
    pros::delay(1000);
    intakeSTOP();


    chassis.moveToPoint(28,121,3000);  //Long movement to middle goal
    chassis.waitUntilDone();
    pros::delay(250);

    chassis.turnToHeading(cardinalWEST,1000);   //Turn to matchloader
    scraperDOWN();
    intakeInFAST();
    chassis.moveToPoint(7,121,1500, {.maxSpeed = 75});  //Matchload 1
    chassis.waitUntilDone();
    pros::delay(700);
    intakeSTOP();


    //--Half Measure--//
    chassis.moveToPoint(24,121,1500, {.forwards = false, .maxSpeed = 90});   //Half Measure
    chassis.turnToHeading(cardinalNORTHWEST, 500);   //Remove bad
    chassis.waitUntilDone();
    scraperUP();
    intakeOutFAST();
    pros::delay(300);
    intakeSTOP();
    chassis.turnToHeading(cardinalWEST, 500);    //Turn to goal
    //--End half measure--//


    chassis.moveToPoint(51,121,1500, {.forwards = false, .maxSpeed = 90});   //Long goal
    chassis.waitUntilDone();
    intakeScore();
    scraperDOWN();
    pros::delay(2500);

    chassis.moveToPoint(7,121,2000, {.maxSpeed = 75});  //Matchload 2
    intakeInFAST();
    chassis.waitUntilDone();
    pros::delay(3000);
    intakeSTOP();

    chassis.moveToPoint(51,121,2000, {.forwards = false, .maxSpeed = 60});   //Long goal 2
    chassis.waitUntilDone();
    intakeScore();
    pros::delay(2500);
    scraperUP();
}


void leftGoalRushSTAY() {
    leftGoalRushMAIN();
    
    chassis.moveToPoint(51,121,10000, {.forwards = false, .maxSpeed = 60});   //Stay at long goal
}

void leftSafeWING() {
    leftGoalRushMAIN();
    
}