#include "main.h"

void printToBoth(const std::string& input){
    pros::lcd::set_text(1, input);
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





void debugAuto() {
    pros::delay(100);
    waitUntilTime();
    leverUpBlocking();
    pros::lcd::set_text(4, "Unblocked");


/*
while (true) {
    pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    pros::delay(50);
}*/
}


bool isLeftLCDPressed() {
    return (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2 == 1;
}

bool isCenterLCDPressed() {
    return (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1 == 1;
}

bool isRightLCDPressed() {
    return (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0 == 1;
}
