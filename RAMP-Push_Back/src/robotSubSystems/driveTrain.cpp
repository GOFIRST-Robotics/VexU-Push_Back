#include "main.h"



pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Motors
pros::MotorGroup left_motor_group({10, -9, 21, -6, 7}, pros::MotorGearset::blue); // left motors use 600 RPM cartridges
pros::MotorGroup right_motor_group({-1, 2, -3, 4, -5}, pros::MotorGearset::blue); // right motors use 600 RPM cartridges


// Odom Sensors
pros::Imu imu(15);
pros::Rotation horizontal_encoder(17);
pros::Rotation vertical_encoder(16);





// drivetrain settings
lemlib::Drivetrain drivetrain(&left_motor_group, // left motor group
                              &right_motor_group, // right motor group
                              11.95, // 10 inch track width
                              lemlib::Omniwheel::NEW_275, // using new 4" omnis
                              600, // drivetrain rpm is 600
                              2 // horizontal drift is 2
);


// horizontal tracking wheel
//----lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_2, -1.906);
// vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, 2, -0.15);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

lemlib::ControllerSettings lateral_controller(6, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD) 4.5
                                              10, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              300, // large error range timeout, in milliseconds
                                              15 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(1, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              0, // anti windup
                                              5, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              10, // large error range, in degrees
                                              1000, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);



//Autonomous Cardinal Direction Shortcuts

int cardinalNORTH = 0;
int cardinalEAST = 90;
int cardinalSOUTH = 180;
int cardinalWEST = 270;

int cardinalNORTHEAST = 45;
int cardinalSOUTHEAST = 135;
int cardinalSOUTHWEST = 225;
int cardinalNORTHWEST = 315;


    //roll, negative is front up
void moveToPark(int x, int y, int timeout, float maxSpeed) {
    int zeroIMU = imu.get_roll();
    chassis.moveToPoint(x, y, timeout, {.maxSpeed = maxSpeed});
    while (imu.get_roll() > zeroIMU-5) {  //While on flat surface
        pros::delay(10);
    }
    chassis.cancelMotion(); //Cancel motion once on park zone

    chassis.tank(127, 127); //Full speed ahead
    while (imu.get_roll() < zeroIMU+1) {  //While not on flat surface
        pros::delay(10);
    }
    pros::delay(150);
    chassis.tank(0, 0); //Stop once tilting to correct angle
}