#include "main.h"   

void rightSKILLS() {  //24 in  
chassis.setPose(24,88,cardinalSOUTH);
intakeInFAST();
pros::delay(500);
drakeUP();


chassis.moveToPoint(24, 120, 1000, {.forwards = false, .maxSpeed = 80});

pros::delay(150);
intakeSTOP();
chassis.turnToHeading(cardinalWEST, 1000);

chassis.moveToPoint(50, 120.5, 1500, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal 1
scraperDOWN();
chassis.tank(-50, -50);
pros::delay(350);
chassis.tank(0, 0);
pros::delay(350);
chassis.setPose(42,120,cardinalWEST);
pros::delay(100);
intakeScore();
pros::delay(750);
intakeOutSLOW();
pros::delay(50);
intakeScore();
pros::delay(750);

intakeInFAST();

///////////////////////////////////////////////////////////////////////////////////////////////////////////PHASE 1 COMPLETE



chassis.moveToPoint(20,120, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 1
chassis.turnToHeading(cardinalWEST, 500, {.earlyExitRange = 2});
chassis.moveToPoint(5, 120, 2000, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 1
intakeSTOP();

chassis.moveToPoint(24, 120, 2000, {.forwards = false, .maxSpeed = 70}, false); //Back away         ######was 120
chassis.turnToHeading(cardinalNORTH, 750, {}, false);
scraperUP();
pros::delay(500);
chassis.moveToPoint(24, 135, 2000, {.maxSpeed = 50}); //Pick up wall blocks
frontAndMidIntake.move_voltage(10000);
chassis.waitUntilDone();
pros::delay(350);

chassis.moveToPoint(24, 133, 2000, {.forwards = false, .maxSpeed = 70}, false); //Cross position
chassis.turnToHeading(cardinalEAST, 750);
frontAndMidIntake.move_voltage(4000);

chassis.moveToPoint(115, 134, 5000, {.maxSpeed = 80}, false); //Cross long
chassis.turnToHeading(cardinalSOUTH, 750);



chassis.moveToPoint(115, 121.5, 4000, {.maxSpeed = 80}, false); //Align to goal
chassis.turnToHeading(cardinalEAST, 750);
scraperDOWN();


chassis.moveToPoint(80, 122.5, 2000, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal 2

chassis.tank(-50, -50);
pros::delay(350);
chassis.tank(0, 0);
pros::delay(350);
chassis.setPose(102,120,cardinalEAST);
pros::delay(100);
intakeScore();
pros::delay(1500);
intakeOutFAST();
pros::delay(100);
intakeScore();
pros::delay(2000);
intakeInFAST();
////////////////////////////////////////////////////////////////////////////////////////////////PHASE 2 COMPLETE
chassis.moveToPoint(120,119, 1000, {.maxSpeed = 100, .minSpeed = 30});  //Match Loader 2
chassis.turnToHeading(cardinalEAST, 500, {.earlyExitRange = 2});
chassis.moveToPoint(140, 119, 2500, {.maxSpeed = 50, .minSpeed = 30}, false);  //Match Loader 2
intakeSTOP();

chassis.moveToPoint(90, 120, 2000, {.forwards = false, .maxSpeed = 50, .minSpeed = 30}, false); //Goal 3
intakeScore();
scraperUP();
pros::delay(1500);
intakeOutFAST();
pros::delay(100);
intakeScore();
pros::delay(2000);
intakeInFAST();

chassis.moveToPoint(112, 73, 2000, {.maxSpeed = 80});   //Align to scrape
intakeSTOP();

chassis.turnToHeading(cardinalEAST, 750);
chassis.moveToPoint(122, 73, 1000, {.maxSpeed = 50}, false);    //Scrape
chassis.moveToPoint(125, 73, 500, {.maxSpeed = 20}, false);    //Scrape

scraperDOWN();
pros::delay(750);
////Wiggle
chassis.turnToHeading(cardinalEAST+20, 350, {.earlyExitRange = 0});
chassis.turnToHeading(cardinalEAST-20, 350, {.earlyExitRange = 0});
chassis.turnToHeading(cardinalEAST+30, 350, {.earlyExitRange = 0});
chassis.turnToHeading(cardinalEAST-30, 350, {.earlyExitRange = 0});
intakeInSLOW();
chassis.moveToPoint(115, 73, 750, {.forwards = false, .maxSpeed = 60}, false);    //Scrape
///Jiggle

chassis.turnToHeading(cardinalNORTHWEST-10, 1000, {.maxSpeed = 50});    //Turn to randoms

chassis.moveToPoint(90, 100, 3000, {.maxSpeed = 80});    //Randoms
intakeInFAST();
pros::delay(250);
scraperUP();
chassis.moveToPoint(75, 100, 3000, {.maxSpeed = 50}, false);    //Randoms


chassis.moveToPoint(88,90, 2000, {.forwards = false, .maxSpeed = 80});    //Randoms back away
scraperDOWN();
chassis.waitUntilDone();
scraperUP();
pros::delay(1000);
chassis.turnToHeading(cardinalSOUTHWEST, 750, {}, false);   //Turn to low goal
intakeInSLOW();

chassis.moveToPoint(85, 83, 1000, {.maxSpeed = 60}, false); //Low goal
chassis.turnToHeading(cardinalSOUTHWEST+20, 500, {},  false);
intakeOutSLOW();
pros::delay(1500);
intakeInFAST();
pros::delay(550);
intakeOutSLOW();
pros::delay(500);

chassis.moveToPoint(95,100, 3000, {.forwards = false, .maxSpeed = 80});    //goal back away
chassis.turnToHeading(cardinalWEST, 750);
intakeInSLOW();
chassis.moveToPoint(11, 100, 2000, {.maxSpeed = 70});   //Move to park position
chassis.turnToHeading(cardinalSOUTH+13, 750);


chassis.moveToPoint(6.5,72,1400, {.maxSpeed = 70});
chassis.waitUntilDone();
chassis.tank(-50, -50); //Full speed back
pros::delay(595);

chassis.tank(10, 10); //Stop once tilting to correct angle
pros::delay(100);
chassis.tank(0, 0); //Stop once tilting to correct angle


    while(true) {
        pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
        pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
        pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
        pros::delay(50);
    }

}