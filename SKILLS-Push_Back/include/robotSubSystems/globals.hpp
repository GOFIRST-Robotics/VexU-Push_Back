#pragma once
#include "main.h"


extern pros::Controller controller;

// Motors
extern pros::MotorGroup left_motor_group; // left motors use 600 RPM cartridges
extern pros::MotorGroup right_motor_group; // right motors use 600 RPM cartridges


extern pros::MotorGroup frontAndMidIntake;  //Front and color sort
extern pros::Motor mainIntake; //Reverse multiplier
extern pros::Motor scoringIntake; //Reverse multiplier


// Odom Sensors
extern pros::Imu imu;
extern pros::Rotation horizontal_encoder;
extern pros::Rotation vertical_encoder;


// Pneumatics
extern pros::adi::Pneumatics scraperPiston;
extern pros::adi::Pneumatics DrakePiston;
extern pros::adi::Pneumatics hoodPiston;