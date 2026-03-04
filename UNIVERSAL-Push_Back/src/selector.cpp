#include "main.h"

int defaultAuto = 2;
int selectedAuto = defaultAuto;
pros::adi::DigitalIn autonSelectButton('B');

void selector(int maxAutos) {
    if (autonSelectButton.get_value()) {
        pros::delay(5);
        if (autonSelectButton.get_value()) {    // Button is pressed
            selectedAuto++;
            if (selectedAuto >= maxAutos) {selectedAuto = 0;}

            while(autonSelectButton.get_value()) {  // Exit condition
                pros::delay(5);
                pros::lcd::set_text(3, "Selector Pressed");
            }
            pros::lcd::clear_line(3);
        }
    }
}