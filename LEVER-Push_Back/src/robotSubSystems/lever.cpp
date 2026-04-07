#include "main.h"


pros::MotorGroup leverMotors({-6,7}, pros::MotorGearset::green);

void getLeverPosition() {
    pros::lcd::set_text(5, std::to_string(leverMotors.get_position()));
}