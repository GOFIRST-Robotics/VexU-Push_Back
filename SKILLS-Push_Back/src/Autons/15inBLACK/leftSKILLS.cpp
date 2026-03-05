#include "main.h"

void leftSKILLS() { //15
    chassis.setPose(25,72, cardinalWEST);
    scraperDOWN();
    intakeInFAST();
    pros::delay(750);
    chassis.moveToPoint(35,72,4000, {.forwards = false, .maxSpeed = 100}, false);    //Pull out

    pros::delay(450);
    scraperUP();
    chassis.moveToPoint(26,72,2000, {.maxSpeed = 40});   //Done

    chassis.turnToHeading(cardinalSOUTH, 750);
    intakeInSLOW();
    chassis.moveToPoint(24,13,3000, {.maxSpeed = 70}, false);  //Wall blocks
    intakeInFAST();

    chassis.turnToHeading(cardinalSOUTH, 350);
    chassis.moveToPoint(24,8, 3000, {.maxSpeed = 40}, false);  //Wall blocks

    pros::delay(750);
    drakeUP();

    chassis.moveToPoint(24, 52.5, 2000, {.forwards = false, .maxSpeed = 80});    //Back away
    chassis.turnToHeading(cardinalEAST, 1000);  //Turn to mid ball
    intakeSTOP();

    chassis.moveToPoint(60, 52.5, 2000, {.maxSpeed = 80}, false); //Mid ball
    scraperDOWN();
    intakeInFAST();
    pros::delay(350);
    chassis.turnToHeading(cardinalEAST - 20, 500);  //Scraper ball break
    chassis.turnToHeading(cardinalEAST + 15, 500);

    chassis.moveToPoint(91, 52.5, 2000, {.maxSpeed = 80}, false); //Low goal alignemnt
    chassis.turnToHeading(cardinalSOUTHEAST+7, 250);
    chassis.moveToPoint(85, 58.5, 2000, {.forwards = false, .maxSpeed = 50}, false);   //Low goal 1
    chassis.turnToHeading(cardinalSOUTHEAST, 250);

    intakeScore();
    pros::delay(1000);
    intakeOutFAST();
    pros::delay(100);
    intakeInSLOW();
    chassis.moveToPoint(92, 51.5, 2000, {.maxSpeed = 50}, false);   //Move away from goal
    chassis.moveToPoint(85, 58.5, 1000, {.forwards = false, .maxSpeed = 50}, false);   //Low goal 2
    intakeScoreSLOW();
    pros::delay(2000);
    intakeOutFAST();
    pros::delay(100);
    intakeScore();
    pros::delay(1500);
    intakeSTOP();

    chassis.moveToPoint(117, 24.5, 3000, {.maxSpeed = 80}, false); //Align to goal
    hoodUP();
    chassis.turnToHeading(cardinalEAST-10, 750);

    chassis.moveToPoint(80, 24, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 30}, false); //Goal align 1
    chassis.tank(-100, -100);
    pros::delay(1000);
    chassis.tank(0, 0);
    pros::delay(250);
    chassis.setPose(102,24,cardinalEAST);
    pros::delay(50);
    intakeScore();
    pros::delay(1000);
    intakeInFAST();
    /////////////////////////////////////////////////RESET


    chassis.moveToPoint(120,24, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
    chassis.turnToHeading(cardinalEAST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(140, 24, 2000, {.maxSpeed = 40, .minSpeed = 30}, false);  //Match Loader 1
    intakeSTOP();

    chassis.moveToPoint(120, 24, 2000, {.forwards = false, .maxSpeed = 70}, false); //Back away
    chassis.turnToHeading(cardinalSOUTH, 750, {}, false);



    scraperUP();
    pros::delay(500);
    chassis.moveToPoint(120, 8, 2000, {.maxSpeed = 50}); //Pick up wall blocks
    intakeOutFAST();
    pros::delay(75);
    intakeInSLOW();
    frontAndMidIntake.move_voltage(10000);
    chassis.waitUntilDone();
    pros::delay(350);

    chassis.moveToPoint(120, 24, 2000, {.forwards = false, .maxSpeed = 90}); //low goal 3 line up position
    pros::delay(350);
    scraperDOWN();

    chassis.turnToHeading(cardinalSOUTHEAST, 750);  //turn to low goal 3
    hoodDOWN();

    chassis.moveToPoint(87, 58, 2000, {.forwards = false, .maxSpeed = 80}, false);   //Low goal 3
    intakeScoreSLOW();
    pros::delay(900);
    intakeInSLOW();

    chassis.moveToPoint(95, 49, 2000, {.maxSpeed = 80}); //Move away from low goal 3
    pros::delay(75);
    intakeInSLOW();
    pros::delay(75);
    intakeSTOP();

    chassis.turnToHeading(cardinalWEST, 750);

    chassis.moveToPoint(29, 48, 3000, {.maxSpeed = 80}, false); //Cross long
    chassis.turnToHeading(cardinalSOUTH, 750);
    hoodUP();





    chassis.moveToPoint(29, 24, 2000, {.maxSpeed = 80}, false); //Align to goal
    chassis.turnToHeading(cardinalWEST, 750);


    chassis.moveToPoint(64, 24.5, 1000, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal score 1

    chassis.tank(-100, -100);
    pros::delay(550);
    chassis.tank(0, 0);
    pros::delay(350);
    chassis.setPose(42,24,cardinalWEST);
    pros::delay(100);
    intakeScore();
    pros::delay(1500);
    intakeOutFAST();
    pros::delay(150);
    intakeScore();
    pros::delay(2000);
    intakeInFAST();
    /////////////////////////////////////////////////////////////RESET 2


        
    chassis.moveToPoint(24,25, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 2
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(4, 25, 2500, {.maxSpeed = 40, .minSpeed = 30}, false);  //Match Loader 2
    intakeSTOP();

    chassis.moveToPoint(54, 24, 2000, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal 2
    intakeScore();
    pros::delay(1500);
    intakeOutFAST();
    pros::delay(150);
    intakeScore();
    pros::delay(2000);
    intakeInFAST();
    scraperUP();
    chassis.moveToPoint(36, 24, 500, {.maxSpeed = 50, .minSpeed = 30}, false); //Goal 2
    chassis.moveToPoint(54, 24, 1000, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal 2
    intakeScore();
    pros::delay(1000);


    chassis.moveToPoint(12, 44, 2000, {.maxSpeed = 100});   //Align to park
    chassis.turnToHeading(cardinalNORTH - 10, 500, {.minSpeed = 30});
//    chassis.moveToPoint(10, 55, 2000, {.maxSpeed = 100});   //Align to park

    moveToPark(6.5,72,1000, 80);



}





/*
#include "main.h"

void leftSKILLS() { //15
    chassis.setPose(25,72, cardinalWEST);
    scraperDOWN();
    intakeInFAST();
    pros::delay(750);
    chassis.moveToPoint(35,72,4000, {.forwards = false, .maxSpeed = 100}, false);    //Pull out

    pros::delay(450);
    scraperUP();
    chassis.moveToPoint(26,72,2000, {.maxSpeed = 40});   //Done

    chassis.turnToHeading(cardinalSOUTH, 750);
    intakeSTOP();

    chassis.moveToPoint(24,13,3000, {.maxSpeed = 70}, false);  //Wall blocks
    intakeInFAST();

    chassis.turnToHeading(cardinalSOUTH, 350);
    chassis.moveToPoint(24,8, 3000, {.maxSpeed = 40}, false);  //Wall blocks

    pros::delay(750);
    chassis.moveToPoint(24, 52.5, 2000, {.forwards = false, .maxSpeed = 80});    //Back away
    chassis.turnToHeading(cardinalEAST, 1000);  //Turn to mid ball
    intakeSTOP();

    chassis.moveToPoint(60, 52.5, 2000, {.maxSpeed = 80}, false); //Mid ball
    scraperDOWN();
    intakeInFAST();
    pros::delay(350);
    chassis.turnToHeading(cardinalEAST - 20, 500);  //Scraper ball break
    chassis.turnToHeading(cardinalEAST + 15, 500);

    chassis.moveToPoint(89, 54, 2000, {.maxSpeed = 80}, false); //Low goal alignemnt
    chassis.turnToHeading(cardinalSOUTHEAST+7, 250);
    chassis.moveToPoint(84, 59, 2000, {.forwards = false, .maxSpeed = 50}, false);   //Low goal 1
    chassis.turnToHeading(cardinalSOUTHEAST, 250);

    intakeScore();
    pros::delay(2000);
    intakeOutFAST();
    pros::delay(150);
    intakeInSLOW();
    chassis.moveToPoint(91, 52, 2000, {.maxSpeed = 50}, false);   //Move away from goal
    chassis.moveToPoint(84, 59, 2000, {.forwards = false, .maxSpeed = 50}, false);   //Low goal 2
    intakeScore();
    pros::delay(1000);
    intakeOutFAST();
    pros::delay(150);
    intakeScore();
    pros::delay(1000);
    intakeInFAST();

    chassis.moveToPoint(117, 24, 3000, {.maxSpeed = 80}, false); //Align to goal
    hoodUP();
    chassis.turnToHeading(cardinalEAST-10, 750);

    chassis.moveToPoint(80, 24, 2000, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal align
    chassis.tank(-90, -90);
    pros::delay(750);
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
    chassis.moveToPoint(120, 8, 2000, {.maxSpeed = 50}); //Pick up wall blocks
    frontAndMidIntake.move_voltage(10000);
    chassis.waitUntilDone();
    pros::delay(350);

    chassis.moveToPoint(120, 12, 2000, {.forwards = false, .maxSpeed = 70}, false); //Cross position
    chassis.turnToHeading(cardinalWEST, 750);
    frontAndMidIntake.move_voltage(5000);



    chassis.moveToPoint(29, 9, 5000, {.maxSpeed = 80}, false); //Cross long
    chassis.turnToHeading(cardinalNORTH, 750);



    chassis.moveToPoint(29, 23, 4000, {.maxSpeed = 80}, false); //Align to goal
    chassis.turnToHeading(cardinalWEST, 750);
    scraperDOWN();


    chassis.moveToPoint(64, 23, 2000, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal score 1

    chassis.tank(-50, -50);
    pros::delay(550);
    chassis.tank(0, 0);
    pros::delay(350);
    chassis.setPose(42,24,cardinalWEST);
    pros::delay(100);
    intakeScore();
    pros::delay(1500);
    intakeOutFAST();
    pros::delay(100);
    intakeScore();
    pros::delay(2000);
    intakeInFAST();
    /////////////////////////////////////////////////////////////RESET


        
    chassis.moveToPoint(24,25, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 2
    chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
    chassis.moveToPoint(4, 25, 2500, {.maxSpeed = 40, .minSpeed = 30}, false);  //Match Loader 2
    intakeSTOP();

    chassis.moveToPoint(54, 24, 2000, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal 2
    intakeScore();
    pros::delay(1500);
    intakeOutFAST();
    pros::delay(100);
    intakeScore();
    pros::delay(2000);
    intakeInFAST();
    scraperUP();


    chassis.moveToPoint(13, 44, 2000, {.maxSpeed = 80});   //Align to park
    chassis.turnToHeading(cardinalNORTH - 10, 750);
    chassis.moveToPoint(8, 55, 2000, {.maxSpeed = 80});   //Align to park

//    chassis.moveToPoint(8, 65, 2000, {.maxSpeed = 80});   //Park


}
*/