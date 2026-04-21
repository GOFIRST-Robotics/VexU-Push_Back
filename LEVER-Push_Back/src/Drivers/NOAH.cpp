#include "main.h"
#include "pros/misc.h"
#include "robotSubSystems/fourBar.hpp"
#include "robotSubSystems/lever.hpp"
#include "robotSubSystems/scraper.hpp"


/** FOR DANIEL
*  Here is the intake motor group
*/
pros::MotorGroup intakeMotors({-13, 14}, pros::MotorGearset::blue);


bool modifier1;
bool score;

int fourBarCounter = 0;
static int FOUR_BAR_DELAY = 20;

int scraperCounter = 0;
static int SCRAPER_DELAY = 20;


bool modifier1;
bool score;

int fourBarCounter = 0;
static int FOUR_BAR_DELAY = 20;

int scraperCounter = 0;
static int SCRAPER_DELAY = 20;

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
        // TODO: Tune in an angle to determine if the lever is high enough to start outtaking
        if (getLeverPosition() >> 30 && !score) {
            intakeMotors.move(-10000); // Outtake
        }
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            if (modifier1) {
                intakeMotors.move(-10000); // Outtake
            }
            else {
                intakeMotors.move(10000); // Intake
            }
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
            intakeMotors.move(-4000); // outtake slowly
        }
        else if (score) {
            intakeMotors.move(10000); // Automatically intake when scoring the lever
        }


        /*
        * ------- Lever Stuff --------
        */
        if (score) {
            if (fourBarPiston.is_extended()) {
                leverUp();
            }
            else {
                // This moves the lever at a slower speed when scoring in the middle goal
                // TODO: Tune in a good max voltage for this motion
                movelever( 320, 9000);
            }
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
        * ------- 4 Bar Controls -------
        */
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
            
            // Only shift state if delay timer has passed
            if (fourBarCounter == 0) {
                if (fourBarPiston.is_extended()) {
                    fourBarDOWN();
                }
                else {
                    fourBarUP();
                }
                
                // Reset timer
                fourBarCounter = FOUR_BAR_DELAY;
            }
        }
        else if (fourBarCounter > 0){
            // Count down timer
            fourBarCounter--;
        }


        /*
        * ------- scraper controls -------  
        */
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && modifier1) {
            
            // Only shift state if delay timer has passed
            if (scraperCounter == 0) {
                if (scraperPiston.is_extended()) {
                    scraperDOWN();
                }
                else {
                    scraperUP();
                }
                
                // Reset timer
                scraperCounter = SCRAPER_DELAY;
            }
        }
        else if (scraperCounter > 0) {
            // Count down timer
            scraperCounter--;
        }


        /*
        * ------- Wing stuff -------  
        */
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            drakeDOWN();
        }
        else {
            drakeUP();
        }

        
        pros::delay(10);
    }
}