#include "main.h"

//NOTE: TRUE IS DOWN, FALSE IS UP

// Drake Shortcuts
void scraperDOWN() {
    scraperPiston.set_value(true);
}

void scraperUP() {
    scraperPiston.set_value(false);
}