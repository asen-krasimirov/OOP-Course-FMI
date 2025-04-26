#pragma once

#include "Mage.h"

class FireMage : public Mage {
private:
    int fire_power;

public:
    FireMage(const my_string& name, int mana, int fire_power);
    void cast_fireball() const;
};

