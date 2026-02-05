#include "main.h"

void rightSKILLS() {
    chassis.setPose(10,56,0);

    //---first score, matchloader, wall balls---///
    chassis.moveToPoint(24, 24, 1500); // move to goal align
    chassis.turnToPoint(15, 24, 500, {.forwards = false});
    chassis.moveToPoint(50, 24, 2000, {.forwards = false, .maxSpeed = 100});   //Goal
    chassis.waitUntilDone();
    intakeScore();
    pros::delay(1000);  //Score preload
    intakeInFAST();
    scraperDOWN();

    chassis.moveToPoint(10, 24, 6000, {.maxSpeed = 80}, false);   //Matchloader
    intakeSTOP();
    scraperUP();
    chassis.moveToPoint(24, 24, 1000, {.forwards = false}); //Back away from matchloader

    chassis.turnToPoint(24, 9, 1000); //Turn to wall blocks
    chassis.moveToPoint(24, 9, 1000); //Move to wall blocks
    chassis.waitUntil(8);
    intakeInFAST();
    chassis.waitUntilDone();
    intakeInSLOW();

    chassis.swingToPoint(96, 14, DriveSide::RIGHT, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE}, false);
    scraperDOWN();
    pros::delay(500);
    //--Ended with intakeInSLOW, scraperDOWN--//


    //--Cross and align to goal--//
    chassis.moveToPoint(96, 14, 3000, {.minSpeed = 70});    //Long cross movement
    chassis.moveToPoint(120, 24, 1000);    //Move to goal align
    chassis.turnToPoint(95, 24, 500, {.forwards = false});  //Turn to goal
    //--Ended with intakeInSLOW, scraperDOWN--//

    //--Score, matchloads--//
    chassis.moveToPoint(95, 24, 2000, {.forwards = false, .maxSpeed = 100}); //Goal scoring
    chassis.waitUntilDone();
    intakeScore();
    pros::delay(5000);  //Score blocks
    intakeInFAST();

    chassis.moveToPoint(135, 24, 6000, {.maxSpeed = 80}, false);   //Matchloader
    chassis.moveToPoint(95, 24, 2000, {.forwards = false, .maxSpeed = 100}); //Goal scoring
    chassis.waitUntilDone();
    intakeScore();
    pros::delay(5000);  //Score blocks
    intakeInSLOW();
    scraperUP();
    //--Ended with intakeInSLOW, scraperUP--//


    //--Grab under goal balls--//
    chassis.swingToPoint(105, 40, DriveSide::LEFT, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE}, false);
    chassis.moveToPoint(105, 40, 1000); //Mid align point

    chassis.turnToPoint(76, 28, 500);
    chassis.moveToPoint(76, 28, 1500, {.maxSpeed = 80}, false); //Under goal balls
    intakeInSLOW();
    scraperDOWN();
    pros::delay(750);
    //--Ended with intakeInSLOW, scraperDOWN--//


    //--Remove park zone balls--//
    chassis.turnToPoint(90, 53, 1000, {.forwards = false, .maxSpeed = 100});    //Middle field align with balls in scraper
    chassis.moveToPoint(90, 53, 2000, {.forwards = false}, false);     //Middle field align
    intakeInFAST();

    chassis.turnToPoint(40, 53, 500, {}, false); //Horizontal move
    pros::delay(500);
    scraperUP();
    
    chassis.moveToPoint(80, 53, 2000, {.maxSpeed = 70, .minSpeed = 70}, false); //Long horizontal move with block pickup
    scraperDOWN();
    chassis.moveToPoint(40, 53, 2000); //Long horizontal move with block pickup

    chassis.turnToPoint(48, 72, 500); //Vertical move
    chassis.moveToPoint(48, 72, 1000, {}, false); 
    scraperUP();
    intakeInSLOW();

    chassis.turnToPoint(24, 72, 500); //Park zone clear position
    chassis.moveToPoint(24, 72, 1000, {.maxSpeed = 60}, false);
    pros::delay(100);
    scraperDOWN();
    pros::delay(750);

    chassis.moveToPoint(34, 72, 2000, {.forwards = false, .maxSpeed = 60}); //Back away from park zone
    //--Ended scraperDOWN, intakeInSLOW--//


    //--Score mid goal, park--//
    chassis.turnToPoint(57, 86, 1000, {.maxSpeed = 100}, false);
    intakeInFAST();
    chassis.moveToPoint(57, 86, 2000, {}, false); //Mid goal align

    chassis.turnToPoint(62, 81, 1000, {.forwards = false});
    chassis.moveToPoint(62, 81, 1000, {.forwards = false, .maxSpeed = 70}, false); //Back into mid goal
    intakeScore();
    pros::delay(3000);  //Score mid goal
    scraperUP();

    chassis.moveToPoint(11, 94, 2000, {.minSpeed = 70}); //Align to park

    chassis.turnToPoint(11, 76, 500, {.minSpeed = 70});
    chassis.moveToPoint(11, 76, 5000); //Park



}