#include "main.h"

float doAtTime = 15000;
pros::adi::DigitalIn timerSelectButton('D');


void timerSelect() {
    if (isCenterLCDPressed()) {// Button is pressed
        doAtTime += 500;
        if (doAtTime >= 30000) {doAtTime = 0;}

        int counter = 0;
        while(isCenterLCDPressed()) {  // Exit condition
            counter++;
            char buffer[50];

            if (counter > 75) {
                counter = 35;
                doAtTime += 500;
                if (doAtTime >= 30000) {doAtTime = 0;}
            }
            sprintf(buffer, "Action at time: %.1f sec", doAtTime/1000.0);
            pros::lcd::set_text(3, buffer);
            pros::delay(10);
        }
    }
    char buffer[50];
    sprintf(buffer, "Action at time: %.1f sec", doAtTime/1000.0);
    pros::lcd::set_text(3, buffer);
    pros::delay(10);
}

uint32_t autonStartTime = 0;
void startTimer() {
    autonStartTime = pros::millis();
}

void waitUntilTime() {
    while (pros::millis() - autonStartTime < doAtTime) {
        pros::delay(10);
    }
}

void waitUntilHardcodeTime(uint32_t time) { //Overloaded for hardcoding action times
    time *= 1000;
    while (pros::millis() - autonStartTime < time) {
        pros::delay(10);
    }
}


