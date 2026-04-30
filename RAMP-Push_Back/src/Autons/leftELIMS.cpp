#include "main.h"


void leftElimsMAIN() {
    printToBoth("Running Left Elims");

    chassis.setPose(24,87.5, cardinalNORTH);

    chassis.moveToPoint(24,118.5, 2000, {.maxSpeed = 90}); //Long movement
    chassis.turnToHeading(cardinalWEST, 1000);    //turn to match loader
    scraperDOWN();
    intakeInFAST();


    chassis.moveToPoint(20,119.5, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(4, 119.5, 750, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 1
    intakeSTOP();
    hoodUP();


    moveToAlignerReset(60, 121, 42, 120, cardinalWEST, 1000);   //Reset Goal 1
    intakeScore();
    pros::delay(850);
    scraperUP();
    intakeSTOP();
}





void leftElimsWing() {
    leftElimsMAIN();


    chassis.moveToPoint(37, 108.25, 1000);   //back away
    scraperUP();
    chassis.turnToHeading(cardinalEAST, 650);
    drakeDOWN();

    chassis.moveToPoint(53, 109.5, 1000);   //Drake


    waitUntilTime();    //Wait to Drake
    chassis.moveToPoint(65, 108.75, 1000);   //Drake
    chassis.waitUntilDone();
    //chassis.tank(5, -5); //low speed back
}


void leftElimsWingDisrupt() {
    leftElimsMAIN();


    chassis.moveToPoint(37, 108.25, 1000);   //back away
    scraperUP();
    chassis.turnToHeading(cardinalEAST, 650);
    drakeDOWN();

    chassis.moveToPoint(65, 108.75, 1000);   //Drake
    chassis.waitUntilDone();
    waitUntilTime();    //Wait to Drake

    drakeUP();
    pros::delay(550);
    chassis.turnToPoint(79, 91, 1000);
    chassis.moveToPoint(79, 89, 2000);
}

