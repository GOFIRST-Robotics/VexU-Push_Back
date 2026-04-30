#pragma once
#include "main.h"

extern pros::adi::DigitalIn autonSelectButton;


void initSelector(int givenDefaultAuto, int givenMaxAutos);
void selector();
int getSelectedAuto();