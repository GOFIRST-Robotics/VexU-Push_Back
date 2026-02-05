#include "main.h"

void leftSKILLS() {
    chassis.setPose(10,87,0);

    //---first score, matchloader, wall balls---///
    chassis.moveToPoint(24, 120, 1500); // move to goal align
    chassis.turnToPoint(15, 120, 500, {.forwards = false});
    chassis.moveToPoint(50, 120, 2000, {.forwards = false, .maxSpeed = 100});   //Goal
    chassis.waitUntilDone();
    intakeScore();
    pros::delay(1000);  //Score preload
    intakeInFAST();
    scraperDOWN();

    chassis.moveToPoint(10, 120, 6000, {.maxSpeed = 80}, false);   //Matchloader
    intakeSTOP();
    scraperUP();
    chassis.moveToPoint(24, 120, 1000, {.forwards = false}); //Back away from matchloader

    chassis.turnToPoint(24, 135, 1000); //Turn to wall blocks
    chassis.moveToPoint(24, 135, 1000); //Move to wall blocks
    chassis.waitUntil(8);
    intakeInFAST();
    chassis.waitUntilDone();
    intakeInSLOW();

    chassis.swingToPoint(96, 130, DriveSide::LEFT, 2000, {.direction = AngularDirection::CW_CLOCKWISE}, false);
    scraperDOWN();
    pros::delay(500);
    //--Ended with intakeInSLOW, scraperDOWN--//


    //--Cross and align to goal--//
    chassis.moveToPoint(96, 130, 3000, {.minSpeed = 70});    //Long cross movement
    chassis.moveToPoint(120, 120, 1000);    //Move to goal align
    chassis.turnToPoint(95, 120, 500, {.forwards = false});  //Turn to goal
    //--Ended with intakeInSLOW, scraperDOWN--//


    //--Score, matchload, wall blocks--//
    chassis.moveToPoint(95, 120, 2000, {.forwards = false, .maxSpeed = 100}); //Goal scoring
    chassis.waitUntilDone();
    intakeScore();
    pros::delay(5000);  //Score blocks
    intakeInFAST();

    chassis.moveToPoint(135, 120, 6000, {.maxSpeed = 80}, false);   //Matchloader
    chassis.moveToPoint(95, 120, 2000, {.forwards = false, .maxSpeed = 100}); //Goal scoring
    chassis.waitUntilDone();
    intakeScore();
    pros::delay(5000);  //Score blocks
    intakeInFAST();
    scraperUP();

    chassis.moveToPoint(120, 120, 1000);    //Move away from goal

    chassis.turnToPoint(120, 135, 500); // Turn to wall blocks
    chassis.moveToPoint(120, 135, 1000);    //Move to wall blocks
    pros::delay(750);
    //--Ended with intakeInFAST, scraperUP--//


    //--Scrape park zone--//
    intakeInSLOW();
    chassis.moveToPoint(110, 72, 2000, {.forwards = false}); //Move to align park zone
    chassis.turnToPoint(120, 72, 500);  //Turn to park zone
    chassis.moveToPoint(120, 72, 2000, {.maxSpeed = 65}, false);   //Move to park zone
    pros::delay(250);
    scraperDOWN();
    pros::delay(750);
    chassis.moveToPoint(110, 72, 2000, {.forwards = false, .maxSpeed = 60}, false); //Move to align park zone
    //--Ended with intakeInSLOW, scraperDOWN--//

    //--Grab last block and score middle goal--//
    chassis.turnToPoint(75, 93, 1000, {.maxSpeed = 90});
    intakeInFAST();
    chassis.moveToPoint(75, 93, 2000);  //Go to mid
    chassis.waitUntil(24);
    scraperUP();
    chassis.waitUntilDone();
    pros::delay(500);

    chassis.moveToPoint(86, 86, 2000, {.forwards = false, .maxSpeed = 90}); //Align to mid goal
    chassis.turnToPoint(81, 81,1000);
    chassis.moveToPoint(81, 81, 1000, {.maxSpeed = 60}, false);
    intakeOutSLOW();
    pros::delay(4000);  //Score mid goal
    //--Ended intakeOUTSLOW, scraperUP--//


    //--Park--//
    chassis.swingToPoint(96, 52, DriveSide::LEFT, 1000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 80});
    chassis.moveToPoint(96, 52, 1500, {.forwards = false}); //Move to far align point

    chassis.moveToPoint(11, 52, 2000);  //Close align
    intakeScore();
    chassis.turnToPoint(11, 67, 500);
    chassis.moveToPoint(11, 67, 5000);  //Park

}