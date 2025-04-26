#include "IceMage.h"

#include <iostream>

IceMage::IceMage(const my_string& name, int mana, int freeze_duration)
    : Mage(name, mana), freeze_duration(freeze_duration) {}

void IceMage::cast_freeze() const {
    if (mana < 40) {
        std:: cout << "No mana...\n";
    else {
        std::cout << "❄️ Freeze cast by " << name << " for " << freeze_duration << " seconds!\n";
    }
}

