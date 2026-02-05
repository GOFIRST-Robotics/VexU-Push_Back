#include "main.h"

int defaultAuto = 5;
int selectedAuto = defaultAuto;
pros::adi::DigitalIn autonSelectButton('B');

void selector(int maxAutos) {
    if (autonSelectButton.get_value()) {
        pros::delay(50);
        if (autonSelectButton.get_value()) {    // Button is pressed
            selectedAuto++;
            if (selectedAuto >= maxAutos) {selectedAuto = 0;}

            while(autonSelectButton.get_value()) {  // Exit condition
                pros::delay(50);
                pros::lcd::set_text(3, "Selector Pressed");
            }
            pros::lcd::clear_line(3);
            pros::delay(50);
        }
    }
}