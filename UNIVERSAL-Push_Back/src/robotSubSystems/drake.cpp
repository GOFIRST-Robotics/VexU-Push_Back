#include "main.h"

//NOTE: TRUE IS DOWN, FALSE IS UP

// Drake Shortcuts
void drakeDOWN() {
    DrakePiston.set_value(true);
}

void drakeUP() {
    DrakePiston.set_value(false);
}