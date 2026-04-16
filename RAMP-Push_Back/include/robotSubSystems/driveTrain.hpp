#pragma once
#include "main.h"
#include "lemlib/api.hpp"



extern pros::Controller controller;

// Motors
extern pros::MotorGroup left_motor_group; // left motors use 600 RPM cartridges
extern pros::MotorGroup right_motor_group; // right motors use 600 RPM cartridges

// Odom Sensors
extern pros::Imu imu;
extern pros::Rotation horizontal_encoder;
extern pros::Rotation vertical_encoder;




// drivetrain settings
extern lemlib::Drivetrain drivetrain;

// horizontal tracking wheel
extern lemlib::TrackingWheel horizontal_tracking_wheel;
// vertical tracking wheel
extern lemlib::TrackingWheel vertical_tracking_wheel;

extern lemlib::OdomSensors sensors;

// lateral PID controller
extern lemlib::ControllerSettings lateral_controller;

// angular PID controller
extern lemlib::ControllerSettings angular_controller;

// create the chassis
extern lemlib::Chassis chassis;


//Autonomous Cardinal Direction Shortcuts

extern int cardinalNORTH;
extern int cardinalEAST;
extern int cardinalSOUTH;
extern int cardinalWEST;

extern int cardinalNORTHEAST;
extern int cardinalSOUTHEAST;
extern int cardinalSOUTHWEST;
extern int cardinalNORTHWEST;

void moveToPark(int x = 8, int y = 72, int timeout = 3000, float maxSpeed = 100);
