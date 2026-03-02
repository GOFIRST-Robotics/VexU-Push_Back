#include "main.h"


void leftSafeMAIN() {
    chassis.setPose(24.5,87.5,cardinalWEST);
    chassis.moveToPoint(53,87, 1000, {.forwards = false, .maxSpeed = 100});    //Align to mid goal
    chassis.turnToHeading(cardinalNORTHWEST, 300);
    chassis.moveToPoint(59,84, 700, {.forwards = false, .maxSpeed = 127}); //Mid goal
    intakeScore();
    chassis.waitUntilDone();
    pros::delay(450);
    intakeSTOP();


    chassis.moveToPoint(26,118, 2000, {.maxSpeed = 100}); //Long movement
    hoodUP();
    chassis.turnToHeading(cardinalWEST-6, 1000);    //turn to match loader
    scraperDOWN();
    intakeInFAST();


    chassis.moveToPoint(20,119, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(11, 119, 1500, {.maxSpeed = 40, .minSpeed = 30}, false);  //Match Loader 1
    holdUntilBlockPresent(3000, 500, false);
    pros::delay(500);
    intakeSTOP();
    scraperUP();


    chassis.moveToPoint(30, 120, 1500, {.forwards = false, .maxSpeed = 80, .minSpeed = 40}, false);   //half measure
    chassis.turnToHeading(cardinalSOUTHWEST, 600, {}, false);
    intakeOutFAST();
    pros::delay(250);
    intakeSTOP();
    chassis.turnToHeading(cardinalWEST+7, 600);


    chassis.moveToPoint(50, 120, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 40}, false);   //Goal 1
    intakeScore();
    scraperDOWN();
    holdUntilBlockRemoved(3000, 500, false);
    intakeInFAST();


    chassis.moveToPoint(20,120, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 2
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(11, 120, 2000, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 2
    pros::delay(1500);
    intakeSTOP();


    chassis.moveToPoint(50,120, 1500, {.forwards = false, .maxSpeed = 60, .minSpeed = 40}, false);   //Goal 2
    intakeScore();
    scraperUP();
    holdUntilBlockRemoved(2000, 500, false);
}


void leftSafeSTAY() {
    printToBoth("Running Left Safe Stay");
    leftSafeMAIN();
    
    chassis.moveToPoint(53,119,10000, {.forwards = false, .maxSpeed = 90});   //Long goal 2
}

void leftSafeWING() {
    printToBoth("Running Left Safe Wing");
    leftSafeMAIN();
    
    intakeSTOP();
    chassis.moveToPoint(37, 110, 1250);   //back away
    chassis.turnToHeading(cardinalWEST, 500);
    chassis.moveToPoint(60, 111, 10000, {.forwards = false, .earlyExitRange = 0});   //Drake
    drakeDOWN();
}