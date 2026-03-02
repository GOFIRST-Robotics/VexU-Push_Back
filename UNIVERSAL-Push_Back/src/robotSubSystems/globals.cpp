#include "main.h"


pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Motors
pros::MotorGroup left_motor_group({1, -8, 3, -4, 5}, pros::MotorGearset::blue); // left motors use 600 RPM cartridges
pros::MotorGroup right_motor_group({-11, 12, -13, 14, -15}, pros::MotorGearset::blue); // right motors use 600 RPM cartridges

pros::MotorGroup frontAndMidIntake({-7, 19}, pros::MotorGearset::blue); //Front and color sort
pros::Motor mainIntake(20, pros::MotorGearset::blue); //Reverse multiplier
pros::Motor scoringIntake(-6, pros::MotorGearset::blue); //Reverse multiplier


// Odom Sensors
pros::Imu imu(16);
pros::Rotation horizontal_encoder(17);
pros::Rotation vertical_encoder(18);


// Pneumatics
pros::adi::Pneumatics scraperPiston('H', false);
pros::adi::Pneumatics DrakePiston('G', true);
pros::adi::Pneumatics hoodPiston('F', false);