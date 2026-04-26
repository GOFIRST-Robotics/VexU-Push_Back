#include "main.h"


void leftStandardMain() {
    printToBoth("Running Left Standard");


    chassis.setPose(24.5,87.5,cardinalWEST);
    chassis.moveToPoint(53,87.5, 1000, {.forwards = false, .maxSpeed = 80});    //Align to mid goal
    chassis.turnToHeading(cardinalNORTHWEST, 300);
    chassis.moveToPoint(61,83, 500, {.forwards = false, .maxSpeed = 127}); //Mid goal
    pros::delay(150);
    intakeScore();
    pros::delay(150);
    


    chassis.moveToPoint(26,118, 2000, {.maxSpeed = 90}); //Long movement
    hoodUP();
    chassis.turnToHeading(cardinalWEST-6, 400);    //turn to match loader
    scraperDOWN();
    intakeInFAST();


    chassis.moveToPoint(20,119.5, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(4, 119.5, 1500, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 1
    intakeSTOP();




    moveToAlignerReset(60, 121, 42, 120, cardinalWEST, 1000);   //Reset Goal 1
    intakeScore();
    pros::delay(700);
    intakeSTOP();


    chassis.moveToPoint(31,121, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Half neatues
    chassis.turnToHeading(cardinalNORTHWEST, 750, {}, false);
    intakeScore();
    pros::delay(600);
    chassis.turnToHeading(cardinalWEST-14, 750, {}, false);



    chassis.moveToPoint(20,121, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 2
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    intakeInFAST();

    chassis.moveToPoint(4, 121, 1500, {.maxSpeed = 50, .minSpeed = 30});  //Match Loader 2
    pros::delay(250);
    intakeInFAST();
    chassis.waitUntilDone();
    pros::delay(750);
    intakeSTOP();


    chassis.moveToPoint(60, 121, 1500, {.forwards = false, .maxSpeed = 65});   //Reset Goal 2
    pros::delay(1000);
    intakeScore();
    scraperUP();
    pros::delay(1350);
    intakeSTOP();
}






void leftStandardWing() {
    leftStandardMain();


    chassis.moveToPoint(37, 109, 1500);   //back away
    scraperUP();
    chassis.turnToHeading(cardinalEAST, 650);
    drakeDOWN();

    chassis.moveToPoint(53, 110, 1000);   //Drake


    waitUntilTime();    //Wait to Drake
    chassis.moveToPoint(65, 108.5, 1000);   //Drake
    chassis.waitUntilDone();
    //chassis.tank(5, -5); //low speed back
}


void leftStandardWingDisrupt() {
    leftStandardMain();


    chassis.moveToPoint(37, 109, 1500);   //back away
    scraperUP();
    chassis.turnToHeading(cardinalEAST, 650);
    

    chassis.moveToPoint(63, 110, 1000);   //Drake
    drakeDOWN();
    chassis.waitUntilDone();
    waitUntilTime();

    drakeUP();
    pros::delay(550);
    
    chassis.turnToPoint(79, 91, 1000);
    chassis.moveToPoint(79, 89, 2000);
}


void leftStandardDisrupt() {
    leftStandardMain();


    chassis.moveToPoint(37, 108, 1500);   //back away
    scraperUP();
    


    chassis.turnToPoint(79, 91, 500);
    chassis.moveToPoint(77.5, 89, 3000);
}