#pragma once

#include "my_string.h"

class Mage {
protected:
    my_string name;
    int mana;

public:
    Mage(const my_string name, int mana);
    void show_info() const;
};
