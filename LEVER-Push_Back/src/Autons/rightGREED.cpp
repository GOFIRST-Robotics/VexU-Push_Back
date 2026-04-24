#include "main.h"


void rightGreedMAIN() {
    printToBoth("Running Right Greed");


    chassis.setPose(24.5,57.5,cardinalEAST);
    scraperDOWN();
    intakeInFAST();
    chassis.turnToPoint(62,43,250);
    //chassis.moveToPoint(56,38, 1500, {.maxSpeed = 80}, false);    //Undergoal
    //chassis.moveToPoint(64,36, 1500, {.maxSpeed = 60}, false);    //Undergoal
    chassis.moveToPoint(62,43, 2000, {.maxSpeed = 120}, false);    //Undergoal
    scraperUP();
    pros::delay(75);
    chassis.turnToHeading(cardinalSOUTH+5, 1000, {}, false);
    chassis.moveToPoint(63,30,1050,{.maxSpeed=60}, false);  //Deep
    intakeInFAST();
    scraperDOWN();
    pros::delay(650);
    scraperUP();
    chassis.moveToPoint(59,44,750,{.forwards = false, .maxSpeed=110});


    chassis.turnToHeading(cardinalSOUTHEAST, 750);
    chassis.moveToPoint(46,48, 1500, {.forwards = false, .maxSpeed = 100}, false);    //Align to mid goal



    chassis.turnToHeading(cardinalNORTHEAST, 500);  // Turn to mid goal
    fourBarUP();
    chassis.waitUntilDone();
    scraperUP();
    pros::delay(550);

    chassis.moveToPoint(56.5,59.5, 1500, {.maxSpeed = 80}); //Mid goal

    chassis.waitUntilDone();
    intakeOutSLOW();
    pros::delay(850);


    chassis.moveToPoint(26,27, 2000, {.forwards = false, .maxSpeed = 100}); //Long movement
    chassis.turnToHeading(cardinalWEST, 1000, {.maxSpeed = 90});    //turn to match loader
    scraperDOWN();
    intakeInFAST();


    chassis.moveToPoint(20,27, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(0, 27, 1750, {.maxSpeed = 50, .minSpeed = 30});  //Match Loader 1
    fourBarUP();




    chassis.moveToPoint(60, 26, 1500, {.forwards = false, .maxSpeed = 65}, false);   //Reset Goal 1
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
    chassis.moveToPoint(4, 26, 2200, {.maxSpeed = 30, .minSpeed = 30}, false);  //Match Loader 2


    chassis.moveToPoint(60, 25, 1500, {.forwards = false, .maxSpeed = 65});   //Reset Goal 2
    pros::delay(1100);
    scraperUP();
    leverUpBlocking();
    pros::delay(75);
    leverUpBlocking();
    intakeOutFAST();
    drakeUP();
}





void rightGreedWing() {
    rightGreedMAIN();


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


void rightGreedWingDisrupt() {
    rightGreedMAIN();


    chassis.moveToPoint(37, 37, 1500);   //back away
    scraperUP();
    chassis.turnToHeading(cardinalEAST, 650);
    drakeDOWN();

    chassis.moveToPoint(53, 32, 1000);   //Drake


    chassis.moveToPoint(64, 36, 1000);   //Drake
    chassis.waitUntilDone();

    waitUntilTime();

    drakeUP();
    pros::delay(550);
    
    chassis.turnToPoint(77, 53, 1000);
    chassis.moveToPoint(77, 55, 2000);
}


void rightGreedDisrupt() {
    rightGreedMAIN();


    chassis.moveToPoint(37, 37, 1500);   //back away
    scraperUP();
    


    chassis.turnToPoint(71, 53, 1000);
    chassis.moveToPoint(71, 55, 2000);
    chassis.swingToHeading(cardinalNORTH, DriveSide::LEFT, 1500, {.direction =AngularDirection::CCW_COUNTERCLOCKWISE});
}