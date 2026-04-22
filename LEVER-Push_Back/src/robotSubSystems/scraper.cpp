#include "main.h"


pros::adi::Pneumatics scraperPiston('H', false);
//NOTE: TRUE IS DOWN, FALSE IS UP

// Scraper Shortcuts
void scraperDOWN() {
    scraperPiston.extend();
}

void scraperUP() {
    scraperPiston.retract();
}