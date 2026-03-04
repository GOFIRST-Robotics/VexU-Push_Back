#include "main.h"

bool beamBreakBroken = false;
void rightSafeMAIN() {
    chassis.setPose(24.5,57.5,90);
    chassis.moveToPoint(54,57, 1000, {.maxSpeed = 100});    //Align to mid goal
    chassis.turnToHeading(cardinalNORTHEAST, 300);
    chassis.moveToPoint(61,61, 700, {.maxSpeed = 127}); //Mid goal
    pros::delay(500);
    intakeOutSLOW();
    chassis.waitUntilDone();
    pros::delay(550);
    intakeSTOP();


    chassis.moveToPoint(26,27, 2000, {.forwards = false, .maxSpeed = 100}); //Long movement
    chassis.turnToHeading(cardinalWEST, 1000, {.maxSpeed = 90});    //turn to match loader
    scraperDOWN();
    intakeInFAST();


    chassis.moveToPoint(20,27, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(4, 27, 2000, {.maxSpeed = 50, .minSpeed = 30});  //Match Loader 1
    if (holdUntilBlockPresent(2000, 500, useBeamBreak)) {beamBreakBroken = true;}
    pros::delay(500);
    intakeSTOP();
    scraperUP();


    chassis.moveToPoint(30, 25, 1500, {.forwards = false, .maxSpeed = 80, .minSpeed = 40}, false);   //half measure
    chassis.turnToHeading(cardinalSOUTHWEST, 600, {}, false);
    intakeOutFAST();
    pros::delay(150);
    intakeSTOP();
    chassis.turnToHeading(cardinalWEST+7, 600);


    chassis.moveToPoint(50, 25, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 40}, false);   //Goal 1
    intakeScore();
    scraperDOWN();
    holdUntilBlockRemoved(750, 250, useBeamBreak);
    intakeOutSLOW();
    pros::delay(100);
    intakeScore();
    pros::delay(750);
    intakeInFAST();


    chassis.moveToPoint(20,27, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 2
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(4, 27, 2000, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 2
    pros::delay(1000);
    intakeSTOP();
    if (!beamBreakBroken) {
        scraperUP();
        chassis.moveToPoint(30, 25, 1500, {.forwards = false, .maxSpeed = 80, .minSpeed = 40}, false);   //half measure
        chassis.turnToHeading(cardinalSOUTHWEST, 600, {}, false);
        intakeOutFAST();
        pros::delay(150);
        intakeSTOP();
        chassis.turnToHeading(cardinalWEST+7, 600);
    }


    chassis.moveToPoint(50,25, 1500, {.forwards = false, .maxSpeed = 60, .minSpeed = 40}, false);   //Goal 2
    intakeScore();
    scraperUP();
    holdUntilBlockRemoved(750, 250, useBeamBreak);  //Score with unjam
    intakeOutSLOW();
    pros::delay(100);
    intakeScore();
    pros::delay(1000);
    intakeInFAST();
}


void rightSafeSTAY() {
    printToBoth("Running Right Safe Stay");
    rightSafeMAIN();
    chassis.moveToPoint(53,25,10000, {.forwards = false, .maxSpeed = 90});   //Long goal 2
}

void rightSafeWING() {
    printToBoth("Running Right Safe Wing");
    rightSafeMAIN();
    
    intakeSTOP();
    chassis.moveToPoint(37, 36.5, 1250);   //back away
    chassis.turnToHeading(cardinalWEST, 500);
    chassis.moveToPoint(60, 35.5, 1000, {.forwards = false, .earlyExitRange = 0});   //Drake
    drakeDOWN();
    chassis.tank(-5, -5); //low speed back

}