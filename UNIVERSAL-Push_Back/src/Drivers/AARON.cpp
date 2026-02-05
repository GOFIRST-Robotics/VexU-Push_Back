#include "main.h"

void driverAARON() {
    controller.print(0,0,"Driver - Aaron");
    while(true) {
        int leftJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        chassis.arcade(leftJoy, rightJoy);


        /*
        * ------- intake stuff -------  
        */
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {     // Color sort
            mainIntake.move_voltage(12000);
            indexerIntake.move_voltage(-12000);
            scoringIntake.move_voltage(0);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {    // Main Intake
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {    // Both buttons to score
                intakeScore();
            }
            else {intakeInFAST(); } // Normal Intake
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {   // Outtake
            intakeOutSLOW();
        }
        else {intakeSTOP(); }


        /*
        * ------- scraper stuff -------  
        */
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            scraperPiston.set_value(true);
        }
        else {
            scraperPiston.set_value(false);
        }


        /*
        * ------- drake stuff -------  
        */
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            drakeDOWN();
        }
        else {
            drakeUP();
        }
        
        pros::delay(10);
    }
}