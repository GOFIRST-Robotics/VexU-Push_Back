#pragma once
#include "main.h"


extern pros::Controller controller;

// Motors
extern pros::MotorGroup left_motor_group; // left motors use 600 RPM cartridges
extern pros::MotorGroup right_motor_group; // right motors use 600 RPM cartridges


extern pros::MotorGroup mainIntake;
extern pros::Motor indexerIntake;
extern pros::Motor scoringIntake;


// Odom Sensors
extern pros::Imu imu;
extern pros::Rotation horizontal_encoder;
extern pros::Rotation vertical_encoder;


// Pneumatics
extern pros::adi::Pneumatics scraperPiston;
extern pros::adi::Pneumatics DrakePiston;