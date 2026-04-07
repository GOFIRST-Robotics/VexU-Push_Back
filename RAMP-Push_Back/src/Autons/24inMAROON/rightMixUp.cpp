#include "main.h"

void rightMixUpMAIN() {
    chassis.setPose(24.5, 57.5, 180);

    chassis.moveToPoint(24.5,27, 2000, {.forwards = false, .maxSpeed = 100}); //Long movement
    chassis.turnToHeading(cardinalWEST, 1000, {.maxSpeed = 90});    //turn to match loader
    scraperDOWN();
    intakeInFAST();


    chassis.moveToPoint(20,27, 1000, {.maxSpeed = 100});  //Match Loader
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(11, 27, 1500, {.maxSpeed = 40, .minSpeed = 30}, false);  //Match Loader
    holdUntilBlockPresent(3000, true);
    pros::delay(500);
    intakeSTOP();
    scraperUP();


    chassis.moveToPoint(30, 25, 1500, {.forwards = false, .maxSpeed = 80, .minSpeed = 40}, false);   //half measure
    chassis.turnToHeading(cardinalSOUTHWEST, 600, {}, false);
    intakeOutFAST();
    pros::delay(150);
    intakeSTOP();
    chassis.turnToHeading(cardinalWEST+7, 600);


    chassis.moveToPoint(50, 25, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 40}, false);   //Goal
    intakeScore();
    scraperDOWN();
    holdUntilBlockRemoved(1000, true);
    intakeInFAST();


    chassis.moveToPoint(20,27, 1000, {.maxSpeed = 100});  //Match Loader
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(11, 27, 2000, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader
    pros::delay(1500);
    intakeSTOP();
    scraperUP();

    chassis.moveToPoint(23, 39, 1000, {.forwards = false, .maxSpeed = 100});    //Back out from match loader
    chassis.turnToPoint(61, 61, 500);

    chassis.moveToPoint(61,61, 700, {.maxSpeed = 127}); //Mid goal
    pros::delay(200);
    intakeOutSLOW();
    chassis.waitUntilDone();
    pros::delay(250);
}


void rightMixUpSTAY() {
    printToBoth("Running Right MixUp Stay");
    rightMixUpMAIN();
    chassis.moveToPoint(61,61,10000, {.forwards = false, .maxSpeed = 90});   //Long goal 2
}

void rightMixUpWING() {
    printToBoth("Running Right MixUp Wing");
    rightMixUpMAIN();
    
    chassis.moveToPoint(40,37,1000, {.maxSpeed = 60});  //move away from goal
    chassis.turnToHeading(cardinalWEST, 1000);
    chassis.moveToPoint(60,36,1000, {.forwards = false, .maxSpeed = 60});   //descore arm
    chassis.waitUntil(15);
    drakeDOWN();
}