#include "FireMage.h"
#include <iostream>

FireMage::FireMage(const my_string& name, int mana, int fire_power)
    : Mage(name, mana), fire_power(fire_power) {}

void FireMage::cast_fireball() const {
    if (mana < 10) {
    	std::cout << "No mana...\n";
    } else {
        std::cout << "Fireball cast by " << name << " with power " << fire_power << "!\n";
    }
}

