#include "main.h"


bool modifier1;
bool score;

int fourBarCounter = 0;
static int FOUR_BAR_DELAY = 20;

int scraperCounter = 0;
static int SCRAPER_DELAY = 20;
int j = 0;
int sc = 0;

int backFlapCloseTimer;
int leverDelay = 10;

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

        if ((getLeverPosition() > 200)) {
            intakeOutFAST();
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
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
        * ------- 4 Bar Flap Controls --------
        */
        if ((score) || (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && modifier1)) {
            backFlapOPEN();
            backFlapCloseTimer = 35;
            
        }
        else {
            if (backFlapCloseTimer < 1) {backFlapCLOSE();}
            backFlapCloseTimer--;
            if (backFlapCloseTimer < 0) {backFlapCloseTimer = 0;}
            
        } 

        /*
        * ------- Lever Stuff --------
        */
        if (score) {
            leverDelay--;
            if (leverDelay < 1) {leverUp();}
            
        }
        else {
           
                leverDown();
                leverDelay = 10;
            
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
        }
        else {
            drakeUP();
        }


        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
            leverMotorLeft.move_voltage(12000);
            leverMotorRight.move_voltage(12000);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
            leverMotorLeft.move_voltage(-12000);
            leverMotorRight.move_voltage(-12000);
        }
        
        pros::delay(10);
    }
}