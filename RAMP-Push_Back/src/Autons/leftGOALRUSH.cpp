#include "main.h"


void leftFourLowSixLong() {
    printToBoth("Running Left Standard");


    chassis.setPose(24.5,87.5, cardinalNORTH);

    chassis.moveToPoint(26,118, 2000, {.maxSpeed = 90}); //Long movement
    chassis.turnToHeading(cardinalWEST-6, 1000);    //turn to match loader
    scraperDOWN();
    intakeInFAST();


    chassis.moveToPoint(20,119, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(4, 119, 1500, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 1
    holdUntilBlockPresent(1000, 500, false);
    intakeInSLOW();
    scraperUP();

    chassis.moveToPoint(59,83, 2000, {.forwards = false, .maxSpeed = 127}); //Mid goal
    intakeOutFAST();
    pros::delay(250);
    intakeSTOP();
    chassis.waitUntilDone();
    intakeScore();
    pros::delay(2000);

    chassis.moveToPoint(26,118, 2000, {.maxSpeed = 90}); //Long movement
    chassis.turnToHeading(cardinalWEST-6, 1000);    //turn to match loader
    intakeInFAST();


    //chassis.moveToPoint(50, 120, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 40}, false);   //Goal 1
    //moveToAlignerReset(60, 120, 42, 120, cardinalWEST, 2000);   //Reset Goal 1
    //intakeScore();
    scraperDOWN();


    chassis.moveToPoint(20,120, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 2
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(4, 120, 2000, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 2
    pros::delay(1500);
    intakeSTOP();


    //chassis.moveToPoint(50,120, 1500, {.forwards = false, .maxSpeed = 60, .minSpeed = 40}, false);   //Goal 2
    moveToAlignerReset(60, 120, 42, 120, cardinalWEST, 2000);   //Reset Goal 2
    intakeScore();
    scraperUP();
    holdUntilBlockRemoved(1000, 500, false);    //Score with unjam
    intakeOutSLOW();
    pros::delay(100);
    intakeScore();
    pros::delay(1000);
    intakeSTOP();


    chassis.moveToPoint(37, 109.5, 1250);   //back away
    chassis.turnToHeading(cardinalWEST, 500);
    

    waitUntilTime();    //Wait to Drake
    chassis.moveToPoint(59, 110.5, 1000, {.forwards = false, .earlyExitRange = 0});   //Drake
    drakeDOWN();
    chassis.tank(-5, -5); //low speed back
}


