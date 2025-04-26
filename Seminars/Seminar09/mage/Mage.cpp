#include "Mage.h"

#include <iostream>

Mage::Mage(const my_string& name, int mana)
    : name(name), mana(mana) {}

void Mage::show_info() const {
    std::cout << "Name: " << name << ", Mana: " << mana << "\n";
}

