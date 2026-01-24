#include "main.h"

void leftQuals() {
        chassis.setPose(24.5,144-57.5,90);

    chassis.moveToPoint(54,144-52,1000, {.maxSpeed = 75});  //Align to mid goal

    chassis.turnToHeading(-45,750, {.maxSpeed = 80});
    chassis.moveToPoint(61,143-59,1000, {.forwards = false, .maxSpeed = 85});  //move to mid goal
    chassis.turnToHeading(-45,750, {.maxSpeed = 90});

    chassis.waitUntilDone();
    mainIntake.move_voltage(12000);
    indexerIntake.move_voltage(12000);
    scoringIntake.move_voltage(12000);
    pros::delay(1000);
    scoringIntake.move_voltage(0);

//    chassis.moveToPoint(48,72,2000);
//    chassis.turnToHeading(-90,1000);
//    chassis.moveToPoint(4,72,3000);

   // scoringIntake.move_voltage(-2000);


    chassis.moveToPoint(28,121,3000, {.maxSpeed = 60});  //Long movement to middle goal
    chassis.waitUntilDone();
    pros::delay(500);

    chassis.turnToHeading(-90,1000);
    scraperPiston.set_value(true);
    indexerIntake.move_voltage(8000);
    mainIntake.move_voltage(8000);
    chassis.waitUntilDone();


    chassis.moveToPoint(7,121,1500, {.maxSpeed = 50});  //Matchload 1
    chassis.waitUntilDone();
    pros::delay(600);
    scraperPiston.set_value(false);
    pros::delay(100);
    mainIntake.move_voltage(0);
    indexerIntake.move_voltage(0);

    chassis.moveToPoint(24,121,1500, {.forwards = false, .maxSpeed = 60});   //Half Measure
    chassis.turnToHeading(-35, 1000);   //Remove bad
    chassis.waitUntilDone();
    mainIntake.move_voltage(-12000);
    indexerIntake.move_voltage(-12000);
    pros::delay(350);
    mainIntake.move_voltage(0);
    indexerIntake.move_voltage(0);
    chassis.turnToHeading(-90, 1000);



    chassis.moveToPoint(51,121,1500, {.forwards = false, .maxSpeed = 60});   //Long goal
    chassis.waitUntilDone();
    mainIntake.move_voltage(12000);
    indexerIntake.move_voltage(12000);
    scoringIntake.move_voltage(12000);
    scraperPiston.set_value(true);

    pros::delay(2500);

    chassis.moveToPoint(7,121,2000, {.maxSpeed = 60});  //Matchload 2
    mainIntake.move_voltage(12000);
    indexerIntake.move_voltage(-12000); //Remove bad balls
   // scoringIntake.move_voltage(-2000);
    chassis.waitUntilDone();
    mainIntake.move_voltage(10000);
    indexerIntake.move_voltage(10000);   //Loading real balls
    pros::delay(3000);

    mainIntake.move_voltage(0);
    indexerIntake.move_voltage(0);
    scraperPiston.set_value(false);
    pros::delay(100);
    scraperPiston.set_value(false);

    chassis.moveToPoint(51,121,2000, {.forwards = false, .maxSpeed = 60});   //Long goal 2
    chassis.waitUntilDone();
    mainIntake.move_voltage(12000);
    indexerIntake.move_voltage(12000);
    scoringIntake.move_voltage(12000);
    pros::delay(2500);
    scraperPiston.set_value(false);

    chassis.moveToPoint(8,121,1000, {.maxSpeed = 60});  //move away from goal
    chassis.turnToHeading(180,1000);

    chassis.moveToPoint(5,45,1000, {.maxSpeed = 90});  //Park
}