#include "main.h"


void leftFourLowSixLongMAIN() {
    printToBoth("Running Left 4low 6long");


    chassis.setPose(24,87.5, cardinalNORTH);

    chassis.moveToPoint(24,118.5, 2000, {.maxSpeed = 90}); //Long movement
    chassis.turnToHeading(cardinalWEST, 1000);    //turn to match loader
    scraperDOWN();
    intakeInFAST();


    chassis.moveToPoint(20,119.5, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(4, 119.5, 1500, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 1
    intakeSTOP();
    scraperUP();


    chassis.moveToPoint(28,119.5, 1000, {.forwards = false, .maxSpeed = 80});    //Align to mid goal
    chassis.turnToHeading(cardinalNORTHWEST, 300);
    chassis.moveToPoint(58,86, 2000, {.forwards = false, .maxSpeed = 75}); //Mid goal
    pros::delay(250);
    hoodUP();
    intakeOutFAST();
    pros::delay(150);


    hoodDOWN();
    intakeInFAST();
    chassis.waitUntilDone();


    waitUntilHardcodeTime(0);
    intakeScore();
    pros::delay(1200);

    chassis.moveToPoint(26,118, 2000, {.maxSpeed = 100}); //Long movement
    chassis.turnToHeading(cardinalWEST-6, 1000);    //turn to match loader
    scraperDOWN();


    chassis.moveToPoint(20,120, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 2
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    intakeInFAST();
    chassis.moveToPoint(4, 120, 1500, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 2
    pros::delay(1000);
    intakeSTOP();
    hoodUP();


    //moveToAlignerReset(60, 121, 42, 120, cardinalWEST, 1000);   //Reset Goal 2
    chassis.moveToPoint(60, 120.6, 1500, {.forwards = false, .maxSpeed = 65});   //Reset Goal 2
    pros::delay(1000);
    intakeScore();
    pros::delay(500);
    intakeOutFAST();
    pros::delay(90);
    intakeScore();
    scraperUP();
    pros::delay(1000);
    intakeSTOP();
}





void leftFourLowSixLongWing() {
    leftFourLowSixLongMAIN();


    chassis.moveToPoint(37, 107.5, 1500);   //back away
    scraperUP();
    chassis.turnToHeading(cardinalEAST, 650);
    drakeDOWN();

    chassis.moveToPoint(53, 109, 1000);   //Drake


    waitUntilTime();    //Wait to Drake
    chassis.moveToPoint(65, 107.5, 1000);   //Drake
    chassis.waitUntilDone();
    //chassis.tank(5, -5); //low speed back
}


void leftFourLowSixLongWingDisrupt() {
    leftFourLowSixLongMAIN();


    chassis.moveToPoint(37, 107.5, 1500);   //back away
    scraperUP();
    chassis.turnToHeading(cardinalEAST, 650);
    

    chassis.moveToPoint(63, 108, 1000);   //Drake
    drakeDOWN();
    chassis.waitUntilDone();
    waitUntilTime();

    drakeUP();
    pros::delay(550);
    
    chassis.turnToPoint(79, 91, 1000);
    chassis.moveToPoint(79, 89, 2000);
}


void leftFourLowSixLongDisrupt() {
    leftFourLowSixLongMAIN();


    chassis.moveToPoint(37, 108, 1500);   //back away
    scraperUP();
    


    chassis.turnToPoint(79, 91, 500);
    chassis.moveToPoint(77.5, 89, 3000);
}