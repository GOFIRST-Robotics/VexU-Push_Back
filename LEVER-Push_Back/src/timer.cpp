#include "main.h"

float doAtTime = 20500;
pros::adi::DigitalIn timerSelectButton('D');


bool lastPressed = false;
int counter = 0;
void timerSelect() {
    bool currentPressed = isCenterLCDPressed();
    if (currentPressed && !lastPressed) {// Button is pressed
        doAtTime += 500;
        if (doAtTime >= 31000) {doAtTime = 0;}
    }
    lastPressed = currentPressed;


    char buffer[50];
    sprintf(buffer, "Action at time: %.1f sec", doAtTime/1000.0);
    pros::lcd::set_text(3, buffer);
    pros::delay(10);
}




uint32_t timerStartTime = 0;
void startTimer() {
    timerStartTime = pros::millis();
}

void waitUntilTime() {
    while (pros::millis() - timerStartTime < doAtTime) {
        pros::delay(10);
    }
}

void waitUntilHardcodeTime(uint32_t time) { //Overloaded for hardcoding action times
    time *= 1000;
    while (pros::millis() - timerStartTime < time) {
        pros::delay(10);
    }
}


