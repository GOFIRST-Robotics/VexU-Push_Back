#include "main.h"


void rightElimsMAIN() {
    printToBoth("Running Right Elims");

    chassis.setPose(24,57.5, cardinalNORTH);

    chassis.moveToPoint(24,26, 2000, {.forwards = false, .maxSpeed = 80}); //Long movement
    chassis.turnToHeading(cardinalWEST, 1000, {.maxSpeed = 90});    //turn to match loader
    scraperDOWN();
    intakeInFAST();


    chassis.moveToPoint(20,25, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
    fourBarUP();
    chassis.turnToHeading(cardinalWEST, 300, {.earlyExitRange = 2});
    chassis.moveToPoint(0, 25, 750, {.maxSpeed = 40, .minSpeed = 30}, false);  //Match Loader 1
    scraperUP();




    chassis.moveToPoint(60, 25, 1500, {.forwards = false, .maxSpeed = 60});   //Reset Goal 2
    pros::delay(1100);
    scraperUP();
    leverUpBlocking();
    pros::delay(75);
    leverUpBlocking();
    intakeOutFAST();
    drakeUP();
}





void rightElimsWing() {
    rightElimsMAIN();


    chassis.moveToPoint(37, 37, 1500);   //back away
    scraperUP();
    chassis.turnToHeading(cardinalEAST, 650);
    drakeDOWN();

    chassis.moveToPoint(55, 32, 1000);   //Drake
    chassis.swingToHeading(cardinalEAST, DriveSide::LEFT, 750, {.direction =AngularDirection::CCW_COUNTERCLOCKWISE});


    waitUntilTime();    //Wait to Drake
    chassis.moveToPoint(67, 37, 1000);   //Drake
    chassis.waitUntilDone();
    //chassis.tank(5, -5); //low speed back
}


void rightElimsWingDisrupt() {
    rightElimsMAIN();


    chassis.moveToPoint(37, 37, 1500);   //back away
    scraperUP();
    chassis.turnToHeading(cardinalEAST, 650);
    drakeDOWN();

    chassis.moveToPoint(52, 33, 1000);   //Drake


    chassis.moveToPoint(66, 37, 1000);   //Drake
    chassis.waitUntilDone();

    waitUntilTime();

    drakeUP();
    pros::delay(550);
    
    chassis.turnToPoint(77, 53, 1000);
    chassis.moveToPoint(77, 55, 2000);
}

