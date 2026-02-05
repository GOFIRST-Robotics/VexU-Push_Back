#pragma once
#include "main.h"
#include "lemlib/api.hpp"


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