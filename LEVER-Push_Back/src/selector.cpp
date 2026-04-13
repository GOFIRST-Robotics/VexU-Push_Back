#include "main.h"

int selectedAuto = 0;
int maxAutos = 0;
pros::adi::DigitalIn autonSelectButton('B');


void initSelector(int givenDefaultAuto, int givenMaxAutos) {
    selectedAuto = givenDefaultAuto;
    maxAutos = givenMaxAutos;
}


void selector() {
    if (isLeftLCDPressed()) {
        selectedAuto++;
        if (selectedAuto > maxAutos) {selectedAuto = 0;}

        while(isLeftLCDPressed()) {  // Exit condition
            pros::delay(5);
        }
    }
    pros::delay(10);
}

int getSelectedAuto() {
    return selectedAuto;
}