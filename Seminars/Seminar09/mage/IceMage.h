#pragma once

#include "Mage.h"

class IceMage : public Mage {
private:
    int freeze_duration;

public:
    IceMage(const my_string& name, int mana, int freeze_duration);
    void cast_freeze() const;
};

