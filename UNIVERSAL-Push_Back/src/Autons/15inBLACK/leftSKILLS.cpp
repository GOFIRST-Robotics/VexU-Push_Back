#include "main.h"

void leftSKILLS() { //15
    chassis.setPose(25,72, cardinalWEST);
    scraperDOWN();
    intakeInFAST();
    pros::delay(1000);
    chassis.moveToPoint(48,72,2000, {.forwards = false, .maxSpeed = 50}, false);    //Pull out
    pros::delay(750);
    chassis.moveToPoint(42,72,2000, {.maxSpeed = 80}, false);    //Pull out

    scraperUP();
    pros::delay(450);
    chassis.moveToPoint(25,72,2000, {.maxSpeed = 40}, false);   //Done
    chassis.turnToHeading(cardinalSOUTH, 750);
    intakeSTOP();

    chassis.moveToPoint(24,13,3000, {.maxSpeed = 70}, false);  //Wall blocks
    chassis.turnToHeading(cardinalSOUTH, 350);
    intakeInFAST();
    chassis.moveToPoint(24,8, 3000, {.maxSpeed = 40}, false);  //Wall blocks

    pros::delay(750);
    chassis.moveToPoint(24, 52.5, 2000, {.forwards = false, .maxSpeed = 80});    //Back away
    chassis.turnToHeading(cardinalEAST, 1000);  //Turn to mid ball
    intakeSTOP();

    chassis.moveToPoint(60, 52.5, 2000, {.maxSpeed = 80}, false); //Mid ball
    scraperDOWN();
    intakeInFAST();
    pros::delay(350);
    chassis.turnToHeading(cardinalEAST - 20, 750);
    chassis.turnToHeading(cardinalEAST + 15, 750);

    chassis.moveToPoint(84, 53, 2000, {.maxSpeed = 80}, false); //Low goal alignemnt
    chassis.turnToHeading(cardinalSOUTHEAST+13, 1000);
    chassis.moveToPoint(82, 58, 2000, {.forwards = false, .maxSpeed = 50}, false);   //Low goal 1
    chassis.turnToHeading(cardinalSOUTHEAST, 250);

    intakeScore();
    pros::delay(2000);
    intakeOutFAST();
    pros::delay(150);
    intakeInSLOW();
    chassis.moveToPoint(89, 51, 2000, {.maxSpeed = 50}, false);   //Move away from goal
    chassis.moveToPoint(83, 59, 2000, {.forwards = false, .maxSpeed = 50}, false);   //Low goal 2
    intakeScore();
    pros::delay(1000);
    intakeOutFAST();
    pros::delay(150);
    intakeScore();
    pros::delay(500);
    intakeInFAST();

    chassis.moveToPoint(117, 24, 3000, {.maxSpeed = 80}, false); //Align to goal
    chassis.turnToHeading(cardinalEAST-10, 750);

    chassis.moveToPoint(80, 24, 2000, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal align
    chassis.tank(-50, -50);
    pros::delay(350);
    chassis.tank(0, 0);
    pros::delay(250);
    chassis.setPose(102,24,cardinalEAST);
    pros::delay(50);
    /////////////////////////////////////////////////RESET


    chassis.moveToPoint(120,24, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
    chassis.turnToHeading(cardinalEAST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(140, 24, 2000, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 1
    intakeSTOP();

    chassis.moveToPoint(120, 24, 2000, {.forwards = false, .maxSpeed = 70}, false); //Back away
    chassis.turnToHeading(cardinalSOUTH, 750, {}, false);



    scraperUP();
    pros::delay(500);
    chassis.moveToPoint(120, 7, 2000, {.maxSpeed = 50}); //Pick up wall blocks
    frontAndMidIntake.move_voltage(10000);
    chassis.waitUntilDone();
    pros::delay(350);

    chassis.moveToPoint(120, 11, 2000, {.forwards = false, .maxSpeed = 70}, false); //Cross position
    chassis.turnToHeading(cardinalWEST, 750);
    frontAndMidIntake.move_voltage(4000);



    chassis.moveToPoint(29, 9, 5000, {.maxSpeed = 80}, false); //Cross long
    chassis.turnToHeading(cardinalNORTH, 750);



    chassis.moveToPoint(29, 22, 4000, {.maxSpeed = 80}, false); //Align to goal
    chassis.turnToHeading(cardinalWEST, 750);
    scraperDOWN();
    hoodUP();


    chassis.moveToPoint(64, 22, 2000, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal 1

    chassis.tank(-50, -50);
    pros::delay(550);
    chassis.tank(0, 0);
    pros::delay(350);
    chassis.setPose(42,24,cardinalWEST);
    pros::delay(100);
    intakeScore();
    pros::delay(3500);
    intakeInFAST();
    /////////////////////////////////////////////////////////////RESET


        
    chassis.moveToPoint(24,25, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 2
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(4, 25, 2500, {.maxSpeed = 40, .minSpeed = 30}, false);  //Match Loader 2
    intakeSTOP();

    chassis.moveToPoint(54, 24, 2000, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal 2
    intakeScore();
    scraperUP();
    pros::delay(3500);
    intakeInFAST();

    chassis.moveToPoint(13, 44, 2000, {.maxSpeed = 80});   //Align to park
    chassis.turnToHeading(cardinalNORTH - 10, 750);
    chassis.moveToPoint(8, 60, 2000, {.maxSpeed = 80});   //Align to park


}