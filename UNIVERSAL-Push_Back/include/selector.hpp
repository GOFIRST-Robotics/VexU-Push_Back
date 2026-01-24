#pragma once
#include "main.h"

extern int defaultAuto;
extern int selectedAuto;
extern pros::adi::DigitalIn autonSelectButton;

void selector(int maxAutos);