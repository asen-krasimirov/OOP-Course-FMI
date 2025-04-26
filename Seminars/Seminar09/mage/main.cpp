#include "FireMage.h"
#include "IceMage.h"
#include "IllusionMage.h"

#include <iostream>

int main() {
    FireMage zara("Zara", 120, 100);
    IceMage olaf("Olaf", 90, 5);

    std::cout << "--- Magic Academy: Spell Showcase ---\n";

    zara.cast_fireball();

    return 0;
}

