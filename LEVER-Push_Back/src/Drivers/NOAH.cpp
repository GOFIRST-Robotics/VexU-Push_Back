#include "main.h"


bool modifier1;
bool score;

int fourBarCounter = 0;
static int FOUR_BAR_DELAY = 20;

int scraperCounter = 0;
static int SCRAPER_DELAY = 20;
int j = 0;
int sc = 0;

void driverNOAH() {
    controller.print(0,0,"Driver - Noah");
    while(true) {
        // Input modifier for second layer of inputs
        modifier1 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);

        // 
        score = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && !modifier1;

        /*
        * ------- Drive stuff -------
        */
        int leftJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        chassis.arcade(leftJoy, rightJoy);

        
        /*
        * ------- intake stuff -------  
        */
        // TODO: This first IF statement checks if the lever is up, and outtakes if it is.
        // We need to find a good value to determine if it is up or not
        if (getLeverPosition() >> 0 && !score) {
            // outtake
        }
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            if (modifier1) {
                intakeOutFAST();
            }
            else {
                intakeInFAST();
            }
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
            intakeOutSLOW();
        }
        else if (score) {
            intakeInFAST();
        }
        else {
            intakeSTOP();
        }


        /*
        * ------- Lever Stuff --------
        */
        if (score) {
            leverUp();
        }
        else {
            leverDown();
        }

        
        /*
        * ------- 4 Bar Flap Controls --------
        */
        if ((score) || (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && modifier1)) {
            backFlapOPEN();
        }
        else {
            backFlapCLOSE();
        } 


        /*
        * ------- scraper controls -------  
        */
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            if(sc == 0) {  //button just pressed
                if (scraperPiston.is_extended()) {
                     scraperUP();
                 }
                 else {
                     scraperDOWN();
                 }
                 sc = 1;
            }
        }
        else {sc = 0;}


        /*
        * ------- 4 Bar Controls -------
        */
        
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
            if(j == 0) {  //button just pressed
                if (fourBarPiston.is_extended()) {
                     fourBarDOWN();
                 }
                 else {
                     fourBarUP();
                 }
                 j = 1;
            }
        }
        else {j = 0;}


            
        //     // Only shift state if delay timer has passed
        //     if (fourBarCounter == 0) {
        //         if (fourBarPiston.is_extended()) {
        //             fourBarDOWN();
        //         }
        //         else {
        //             fourBarUP();
        //         }
                
        //         // Reset timer
        //         fourBarCounter = FOUR_BAR_DELAY;
        //     }
        // }
        // else if (fourBarCounter > 0){
        //     // Count down timer
        //     fourBarCounter--;
        // }


        /*
        * ------- Wing stuff -------  
        */
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !modifier1) {
            drakeDOWN();
            //scraperDOWN();
        }
        else {
            drakeUP();
            //scraperUP();
        }

        
        pros::delay(10);
    }
}