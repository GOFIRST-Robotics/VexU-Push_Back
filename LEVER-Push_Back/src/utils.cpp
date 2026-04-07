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








void debugAuto() {

while (true) {
    pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    pros::delay(50);
}
}





uint32_t autonStartTime = 0;
uint32_t doAtTime = 0;

void initTimer() {
    autonStartTime = pros::millis();
}

void waitUntilTime() {
    while (pros::millis() - autonStartTime < doAtTime) {
        pros::delay(10);
    }
}

void waitUntilTime(uint32_t time) { //Overloaded for hardcoding action times
    time *= 1000;
    while (pros::millis() - autonStartTime < time) {
        pros::delay(10);
    }
}


pros::adi::DigitalIn timerSelectButton('D');

void timerSelect() {
    if (timerSelectButton.get_value()) {
        pros::delay(5);
        if (timerSelectButton.get_value()) {    // Button is pressed
            doAtTime += 500;
            if (doAtTime >= 30000) {doAtTime = 0;}
            pros::lcd::set_text(4, std::to_string(doAtTime/1000));

            while(timerSelectButton.get_value()) {  // Exit condition
                pros::delay(5);
            }
        }
    }
}