#include "main.h"

void printToBoth(const std::string& input){
    pros::lcd::set_text(0, input);
    controller.clear_line(0);
    pros::delay(75);
    controller.print(0,0, "%s", input.c_str());
}

// Tasks
void printOdom() {
    pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    pros::delay(50);
}







void debugAuto15() {
   // chassis.setPose(24.5,87.55,90);

}

void debugAuto24() {


    //chassis.setPose(0,0,0);
  //  chassis.moveToPoint(0, 48, 10000, {.maxSpeed = 100});
 //   pros::delay(100);
   // chassis.turnToHeading(180,5000);
//pros::delay(100);
   // chassis.moveToPoint(0, 0, 10000);

while (true) {
    pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    pros::delay(50);
}
}

//cardinalNORTHEAST