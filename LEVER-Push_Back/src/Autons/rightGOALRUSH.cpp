#include "main.h"


void rightFourLowSixLongMAIN() {
    printToBoth("Running Right 4low 6long");


    chassis.setPose(24,57.5, cardinalNORTH);

    chassis.moveToPoint(24,26, 2000, {.forwards = false, .maxSpeed = 80}); //Long movement
    chassis.turnToHeading(cardinalWEST, 1000, {.maxSpeed = 90});    //turn to match loader
    scraperDOWN();
    intakeInFAST();


    chassis.moveToPoint(20,25, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
    chassis.turnToHeading(cardinalWEST, 300, {.earlyExitRange = 2});
    chassis.moveToPoint(0, 25, 1750, {.maxSpeed = 40, .minSpeed = 30}, false);  //Match Loader 1
    scraperUP();
    


    chassis.moveToPoint(24,26, 1000, {.forwards = false, .maxSpeed = 100});    //Align to mid goal

    fourBarUP();

    intakeInFAST();
    chassis.turnToHeading(cardinalNORTHEAST, 500);
    pros::delay(250);
    intakeOutFAST();
    pros::delay(350);   //Extake opps
    intakeInFAST();
    chassis.moveToPoint(59,62, 2500, {.maxSpeed = 80}, false); //Mid goal
    intakeOutSLOW();
    pros::delay(1000);


    chassis.moveToPoint(26,27, 2000, {.forwards = false, .maxSpeed = 80}); //Long movement
    chassis.turnToHeading(cardinalWEST, 1000);    //turn to match loader
    scraperDOWN();


    chassis.moveToPoint(20,28, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 2
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    intakeInFAST();
    chassis.moveToPoint(4, 28, 2000, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 2



    chassis.moveToPoint(60, 26, 1500, {.forwards = false, .maxSpeed = 60});   //Reset Goal 2
    pros::delay(1100);
    scraperUP();
    leverUpBlocking();
    pros::delay(75);
    leverUpBlocking();
    intakeOutFAST();
    drakeUP();
}





void rightFourLowSixLongWing() {
    rightFourLowSixLongMAIN();


    chassis.moveToPoint(37, 37, 1500);   //back away
    scraperUP();
    chassis.turnToHeading(cardinalEAST, 650);
    drakeDOWN();

    chassis.moveToPoint(52, 33, 1000);   //Drake
    chassis.swingToHeading(cardinalEAST, DriveSide::LEFT, 750, {.direction =AngularDirection::CCW_COUNTERCLOCKWISE});


    waitUntilTime();    //Wait to Drake
    chassis.moveToPoint(67, 37, 1000);   //Drake
    chassis.waitUntilDone();
    //chassis.tank(5, -5); //low speed back
}


void rightFourLowSixLongWingDisrupt() {
    rightFourLowSixLongMAIN();


    chassis.moveToPoint(37, 37, 1500);   //back away
    scraperUP();
    chassis.turnToHeading(cardinalEAST, 650);
    drakeDOWN();

    chassis.moveToPoint(52, 33, 1000);   //Drake


    chassis.moveToPoint(64, 37, 1000);   //Drake

    chassis.waitUntilDone();

    waitUntilTime();

    drakeUP();
    pros::delay(550);
    
    chassis.turnToPoint(77, 53, 1000);
    chassis.moveToPoint(77, 55, 2000);
}


void rightFourLowSixLongDisrupt() {
    rightFourLowSixLongMAIN();


    chassis.moveToPoint(37, 37, 1500);   //back away
    scraperUP();
    


    chassis.turnToPoint(71, 53, 1000);
    chassis.moveToPoint(71, 55, 2000);
    chassis.swingToHeading(cardinalNORTH, DriveSide::LEFT, 1500, {.direction =AngularDirection::CCW_COUNTERCLOCKWISE});
}