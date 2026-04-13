#include "main.h"


void leftStandard() {
    printToBoth("Running Left Standard");


    chassis.setPose(24.5,87.5,cardinalWEST);
    chassis.moveToPoint(53,86, 1000, {.forwards = false, .maxSpeed = 90});    //Align to mid goal
    chassis.turnToHeading(cardinalNORTHWEST, 300);
    chassis.moveToPoint(59,83, 700, {.forwards = false, .maxSpeed = 127}); //Mid goal
    chassis.waitUntilDone();
    intakeScore();
    pros::delay(750);
    intakeSTOP();


    chassis.moveToPoint(26,118, 2000, {.maxSpeed = 90}); //Long movement
    hoodUP();
    chassis.turnToHeading(cardinalWEST-6, 1000);    //turn to match loader
    scraperDOWN();
    intakeInFAST();


    chassis.moveToPoint(20,119, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(4, 119, 2500, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 1
    holdUntilBlockPresent(1000, 500, false);
    pros::delay(500);
    intakeSTOP();
    scraperUP();


    chassis.moveToPoint(30, 120, 1500, {.forwards = false, .maxSpeed = 80, .minSpeed = 40}, false);   //half measure
    chassis.turnToHeading(cardinalSOUTHWEST, 600, {}, false);
    intakeOutFAST();
    pros::delay(250);
    intakeSTOP();
    chassis.turnToHeading(cardinalWEST+7, 600);


    //chassis.moveToPoint(50, 120, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 40}, false);   //Goal 1
    moveToAlignerReset(60, 120, 42, 120, cardinalWEST, 2000);   //Reset Goal 1
    intakeScore();
    scraperDOWN();
    holdUntilBlockRemoved(2000, 500, false);
    intakeOutSLOW();
    pros::delay(100);
    intakeScore();
    pros::delay(750);
    intakeInFAST();

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


