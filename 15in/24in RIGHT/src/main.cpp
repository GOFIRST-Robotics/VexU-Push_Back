#include "main.h"
#include "lemlib/api.hpp"
#include "shortcutFuncs.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::adi::Pneumatics scraperPiston('H', false);
pros::adi::Pneumatics DrakePiston('G', false);

// Drake toggleable mode vars
int drakeI = 0;
bool drakeOut = false; // false = stowed, true = deployed
#define DRAKE_DELAY 20; // cycles per command sent to drake

pros::MotorGroup mainIntake({6, 7}, pros::MotorGearset::blue);
pros::Motor indexerIntake(-19, pros::MotorGearset::blue);
pros::Motor scoringIntake(-20, pros::MotorGearset::blue);

//Drivetrain Setup
pros::MotorGroup left_motor_group({1, -8, 3, -4, 5}, pros::MotorGearset::blue); // left motors use 600 RPM cartridges
pros::MotorGroup right_motor_group({-11, 12, -13, 14, -15}, pros::MotorGearset::blue); // right motors use 600 RPM cartridges

// drivetrain settings
lemlib::Drivetrain drivetrain(&left_motor_group, // left motor group
                              &right_motor_group, // right motor group
                              11.95, // 10 inch track width
                              lemlib::Omniwheel::NEW_275, // using new 4" omnis
                              600, // drivetrain rpm is 600
                              2 // horizontal drift is 2
);

// create an imu on port 13
pros::Imu imu(16);

// horizontal tracking wheel encoder
pros::Rotation horizontal_encoder(17);
// vertoal tracking wheel encoder
pros::Rotation vertical_encoder(18);

// horizontal tracking wheel
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_2, -1.906);
// vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, -0.15);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(6.7, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              6, // derivative gain (kD) 4.5
                                              10, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              2, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(1, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              2, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in degrees
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in degrees
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);

//ADI Inputs
pros::ADIDigitalIn driverSelect1('A');
pros::ADIDigitalIn driverSelect2('B');
int driverVar = 2; // 1 noah 2 aaron

// Tasks
void printOdom() {
    pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    pros::delay(50);
}





/////////////////////////////////////////////


void rightSafe() {
   //pros::Task colorSortTask(colorSort);
    chassis.setPose(24.5,57.5,90);
    scoringIntake.move_voltage(10000);

    chassis.moveToPoint(55,55,1000, {.maxSpeed = 75});  //Align to mid goal
    pros::delay(250);
    scoringIntake.move_voltage(-2000);


    chassis.turnToHeading(45,750, {.maxSpeed = 80});
    chassis.moveToPoint(61,61,1000, {.maxSpeed = 60});  //move to mid goal
    chassis.waitUntilDone();
    mainIntake.move_voltage(-7000);
    indexerIntake.move_voltage(-8000);
    pros::delay(1000);

    chassis.moveToPoint(28,24,3000, {.forwards = false, .maxSpeed = 60});  //Long movement to middle goal
    chassis.waitUntilDone();
    pros::delay(500);

    chassis.turnToHeading(-90,1000);
    scraperPiston.set_value(true);
    indexerIntake.move_voltage(8000);
    mainIntake.move_voltage(8000);
    chassis.waitUntilDone();


    chassis.moveToPoint(7,24,1500, {.maxSpeed = 53});  //Matchload 1
    chassis.waitUntilDone();
    pros::delay(1000);
    scraperPiston.set_value(false);
    pros::delay(100);
    mainIntake.move_voltage(0);
    indexerIntake.move_voltage(0);



    chassis.moveToPoint(25,24,1500, {.forwards = false, .maxSpeed = 60});   //back away from Matchload 1
    chassis.turnToHeading(-135,1000);

    chassis.moveToPoint(48,44,1500, {.forwards = false, .maxSpeed = 60});   //align to drive back
    chassis.turnToHeading(-90,1000);
    chassis.moveToPoint(96,44,1500, {.forwards = false, .maxSpeed = 90});   //drive by goal
    chassis.turnToHeading(135,1000);

    chassis.moveToPoint(120,24,1500, {.maxSpeed = 70});   //align to score
    chassis.turnToHeading(90,1000);



    chassis.moveToPoint(92,22,1500, {.forwards = false, .maxSpeed = 60});   //Long goal
    chassis.waitUntilDone();
    mainIntake.move_voltage(12000);
    indexerIntake.move_voltage(12000);
    scoringIntake.move_voltage(12000);
    scraperPiston.set_value(true);

    pros::delay(2500);
    scoringIntake.move_voltage(-2000);

    chassis.moveToPoint(139,22,2000, {.maxSpeed = 55});  //Matchload 2
    mainIntake.move_voltage(10000);
    indexerIntake.move_voltage(10000);   //Loading balls
    chassis.waitUntilDone();
    pros::delay(3000);

    scraperPiston.set_value(false);
    mainIntake.move_voltage(0);
    indexerIntake.move_voltage(0);
    pros::delay(250);


    chassis.moveToPoint(92,22,1500, {.forwards = false, .maxSpeed = 60});   //Long goal 2
    chassis.waitUntilDone();
    mainIntake.move_voltage(12000);
    indexerIntake.move_voltage(12000);
    scoringIntake.move_voltage(12000);

    chassis.moveToPoint(134,44,1000, {.maxSpeed = 60});  //move away from goal
    chassis.turnToHeading(-90,1000);

    chassis.moveToPoint(12,44,5000);
    chassis.turnToHeading(0,1000);

    chassis.moveToPoint(12,82,5000);    //Park


}


/////////////////////////////////


//Intake shortcuts
void intakeIN(){
    mainIntake.move_voltage(12000);
}

void intakeOUT(){
    mainIntake.move_voltage(-12000);
    scoringIntake.move_voltage(-12000);
}

void intakeCustomSpeed(int voltage){
    mainIntake.move_voltage(voltage);
}

void intakeScore() {
    mainIntake.move_voltage(12000);
    scoringIntake.move_voltage(12000);
}

void colorSort() {
//    if (oppcolor) {
//    indexerIntake.move_voltage(-12000);
//}
//else {
//    indexerIntake.move_voltage(12000);
//}
pros::delay(10);
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    pros::delay(250);
    
    //Setting Driver
    if (!driverSelect1.get_value() && driverSelect2.get_value()) {driverVar = 1;}
    else if (driverSelect1.get_value() && !driverSelect2.get_value()) {driverVar = 2;}
    else if (driverSelect1.get_value() && driverSelect2.get_value()) {driverVar = 3;}


    //while(true) {
     //   controller.print(1,0,"Auto: ");
        pros::delay(50);
   // }
 //   pros::Task printOdomTask(printOdom);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  //  rightSafe();
      mainIntake.move_voltage(8000);

    
    //while(true) {
    //        pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    //pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    //pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    //pros::delay(50);
    //}

}



void setIntake() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {    //Top button normal intake
        mainIntake.move_voltage(12000);
        indexerIntake.move_voltage(12000);
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {    //Both buttons score
            scoringIntake.move_voltage(12000);
        }
    }
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {   //Bottom button reverse
        mainIntake.move_voltage(-7000);
        indexerIntake.move_voltage(-7000);
    }
    else {
        mainIntake.move_voltage(0);
        indexerIntake.move_voltage(0);
        scoringIntake.move_voltage(-1000);
    }

}

void setScraper() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        scraperPiston.set_value(true);
    }
    else {
        scraperPiston.set_value(false);
    }
}

void setDrake() {

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        DrakePiston.set_value(true);
    }
    else {
        DrakePiston.set_value(false);
    }


    // below: Toggleable mode

    // if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && drakeI >> DRAKE_DELAY) {
        
    //     // flip drake state
    //     drakeOut = !drakeOut;
            
    //     // send command to drake
    //     DrakePiston.set_value(drakeOut);
        
    //     // reset timer
    //     drakeI = 0;
    // }
    // else {

    //     // increase timer
    //     drakeI++;
    // }
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    //pros::Task colorSortTask(colorSort);
    if (driverVar == 0) {   // Daniel
        controller.print(0,0,"Welcome, Fuckass");
        //autonomous();
        while (true) {
            int leftJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            int rightJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
            chassis.tank(leftJoy, rightJoy);
            setIntake();
            setScraper();
            pros::delay(10);
        }
    }

    else if (driverVar == 1) {   // Noah
        controller.print(0,0,"Welcome, Noah");
        while (true) {
            int leftJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            int rightJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
            chassis.arcade(leftJoy, rightJoy);
            setIntake();
            setScraper();
            setDrake();
            pros::delay(10);
        }
    }

    else if (driverVar == 2) {   // Aaron
        controller.print(0,0,"Welcome, Aaron");
        while (true) {
            int leftJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            int rightJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
                leftJoy *= 0.4;
                rightJoy *= 0.4;
            }

            chassis.arcade(leftJoy, rightJoy);

            /*
            * ------- intake stuff -------  
            */

            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {     // Color sort
                mainIntake.move_voltage(12000);
                indexerIntake.move_voltage(-12000);
                scoringIntake.move_voltage(-3000);
            }
            else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {    // Normal Intake
                mainIntake.move_voltage(12000);
                indexerIntake.move_voltage(12000);

                if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {    // Both buttons to score
                    scoringIntake.move_voltage(12000);
                }
                else {
                    scoringIntake.move_voltage(-3000);
                }
            }
            else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {   // Outtake
                mainIntake.move_voltage(-7000);
                indexerIntake.move_voltage(-7000);
                scoringIntake.move_voltage(-3000);
            }
            else {
                mainIntake.move_voltage(0);
                indexerIntake.move_voltage(0);
                scoringIntake.move_voltage(-3000);
            }

            /*
            * ------- scraper stuff -------  
            */

            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
                scraperPiston.set_value(true);
            }
            else {
                scraperPiston.set_value(false);
            }

            /*
            * ------- drake stuff -------  
            */

            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
                DrakePiston.set_value(true);
            }
            else {
                DrakePiston.set_value(false);
            }

            // Resource saving delay
            pros::delay(10);
        }
    }
}

void opControlFunctions() {
setIntake();
setScraper();
pros::delay(10);
}

