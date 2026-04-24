#include "main.h"


void rightStandardMain() {
    printToBoth("Running Right Standard");


    chassis.setPose(24.5,57.5,cardinalEAST);
    chassis.moveToPoint(53,57.5, 1000, {.maxSpeed = 100});    //Align to mid goal
    chassis.turnToHeading(cardinalNORTHEAST, 300);
    chassis.moveToPoint(59,62, 700, {.maxSpeed = 127}); //Mid goal
    //pros::delay(500);
    intakeOutSLOW();
    chassis.waitUntilDone();
    pros::delay(550);
    intakeSTOP();


    chassis.moveToPoint(26,27, 2000, {.forwards = false, .maxSpeed = 100}); //Long movement
    chassis.turnToHeading(cardinalWEST, 1000, {.maxSpeed = 90});    //turn to match loader
    scraperDOWN();
    intakeInFAST();


    chassis.moveToPoint(20,28, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(0, 27, 1500, {.maxSpeed = 50, .minSpeed = 30});  //Match Loader 1
    fourBarUP();




    chassis.moveToPoint(60, 25, 1500, {.forwards = false, .maxSpeed = 65}, false);   //Reset Goal 1
    leverSetCustomTarget(265);
    pros::delay(50);
    intakeOutFAST();
    scraperUP();


    chassis.moveToPoint(32,26, 1500, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 2


    chassis.turnToHeading(cardinalSOUTHWEST, 500, {.earlyExitRange = 2}, false);
    backFlapCLOSE();
    leverDown();
    pros::delay(750);
    chassis.turnToHeading(cardinalWEST+9, 500, {.earlyExitRange = 2});
    scraperDOWN();
    pros::delay(350);


    intakeInFAST();
    chassis.moveToPoint(4, 26, 2000, {.maxSpeed = 30, .minSpeed = 30}, false);  //Match Loader 2


    chassis.moveToPoint(60, 25, 1500, {.forwards = false, .maxSpeed = 65});   //Reset Goal 2
    pros::delay(1100);
    scraperUP();
    leverUpBlocking();
    pros::delay(75);
    leverUpBlocking();
    intakeOutFAST();
    drakeUP();
}





void rightStandardWing() {
    rightStandardMain();


    chassis.moveToPoint(37, 37, 1500);   //back away
    scraperUP();
    chassis.turnToHeading(cardinalEAST, 650);
    drakeDOWN();

    chassis.moveToPoint(53, 32, 1000);   //Drake
    chassis.swingToHeading(cardinalEAST, DriveSide::LEFT, 750, {.direction =AngularDirection::CCW_COUNTERCLOCKWISE});


    waitUntilTime();    //Wait to Drake
    chassis.moveToPoint(67, 36, 1000);   //Drake
    chassis.waitUntilDone();
    //chassis.tank(5, -5); //low speed back
}


void rightStandardWingDisrupt() {
    rightStandardMain();


    chassis.moveToPoint(37, 37, 1500);   //back away
    scraperUP();
    chassis.turnToHeading(cardinalEAST, 650);
    drakeDOWN();

    chassis.moveToPoint(53, 32, 1000);   //Drake


    chassis.moveToPoint(66, 36, 1000);   //Drake
    chassis.waitUntilDone();

    waitUntilTime();

    drakeUP();
    pros::delay(550);
    
    chassis.turnToPoint(77, 53, 1000);
    chassis.moveToPoint(77, 55, 2000);
}


void rightStandardDisrupt() {
    rightStandardMain();


    chassis.moveToPoint(37, 37, 1500);   //back away
    scraperUP();
    


    chassis.turnToPoint(71, 53, 1000);
    chassis.moveToPoint(71, 55, 2000);
    chassis.swingToHeading(cardinalNORTH, DriveSide::LEFT, 1500, {.direction =AngularDirection::CCW_COUNTERCLOCKWISE});
}