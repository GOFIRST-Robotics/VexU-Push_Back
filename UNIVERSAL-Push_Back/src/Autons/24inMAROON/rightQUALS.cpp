#include "main.h"

void rightQuals() {
    chassis.setPose(24.5,57.5,90);
    scoringIntake.move_voltage(10000);

    chassis.moveToPoint(55,55,1000, {.maxSpeed = 75});  //Align to mid goal
    pros::delay(250);
    scoringIntake.move_voltage(-2000);


    chassis.turnToHeading(45,750, {.maxSpeed = 80});
    chassis.moveToPoint(61,61,1000, {.maxSpeed = 60});  //move to mid goal
    chassis.waitUntilDone();
    mainIntake.move_voltage(-6000);
    indexerIntake.move_voltage(-8000);
    pros::delay(1000);

    chassis.moveToPoint(28,24,3000, {.forwards = false, .maxSpeed = 60});  //Long movement to middle goal
    chassis.waitUntilDone();
    pros::delay(500);

    chassis.turnToHeading(-90,1000);
    scraperPiston.set_value(true);
    indexerIntake.move_voltage(8000);
    mainIntake.move_voltage(8000);
    chassis.waitUntilDone();


    chassis.moveToPoint(7,24,2000, {.maxSpeed = 53});  //Matchload 1

chassis.waitUntilDone();
    pros::delay(700);
    scraperPiston.set_value(false);
    pros::delay(25);
    mainIntake.move_voltage(0);
    indexerIntake.move_voltage(0);

    chassis.moveToPoint(24,24,1500, {.forwards = false, .maxSpeed = 60});   //Half Measure
    chassis.turnToHeading(-135, 1000);   //Remove bad
    chassis.waitUntilDone();
    mainIntake.move_voltage(-12000);
    indexerIntake.move_voltage(-12000);
    pros::delay(300);
    mainIntake.move_voltage(0);
    indexerIntake.move_voltage(0);
    chassis.turnToHeading(-90, 1000);



    chassis.moveToPoint(50,23,2000, {.forwards = false, .maxSpeed = 60});   //Long goal
    chassis.waitUntilDone();
    mainIntake.move_voltage(12000);
    indexerIntake.move_voltage(12000);
    scoringIntake.move_voltage(12000);
    scraperPiston.set_value(true);

    pros::delay(2500);

    chassis.moveToPoint(7,24,2000, {.maxSpeed = 53});  //Matchload 2
    mainIntake.move_voltage(12000);
    indexerIntake.move_voltage(8000); //Remove bad balls
    scoringIntake.move_voltage(-2000);
    chassis.waitUntilDone();
    pros::delay(1000);
    mainIntake.move_voltage(8000);
    indexerIntake.move_voltage(8000);   //Loading real balls
    pros::delay(3000);

    mainIntake.move_voltage(0);
    indexerIntake.move_voltage(0);
    scraperPiston.set_value(false);
    pros::delay(25);
    scraperPiston.set_value(false);

    chassis.moveToPoint(51,23,2000, {.forwards = false, .maxSpeed = 55});   //Long goal 2
    chassis.waitUntilDone();
    mainIntake.move_voltage(12000);
    indexerIntake.move_voltage(12000);
    scoringIntake.move_voltage(12000);
    pros::delay(2500);
    scraperPiston.set_value(false);


    chassis.moveToPoint(30,37,1000, {.maxSpeed = 60});  //move away from goal
    chassis.turnToHeading(-90,1000);
    chassis.moveToPoint(60,36,1000, {.forwards = false, .maxSpeed = 60});   //descore arm
    pros::delay(500);
    DrakePiston.set_value(true);
    pros::delay(750);
    //DrakePiston.set_value(true);
}