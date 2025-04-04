#include "bus.h"

int main() {
    int capacity, cargo_slots;
    double fuel;

    std::cout << "Enter bus capacity, initial fuel level, and cargo slots: ";
    std::cin >> capacity >> fuel >> cargo_slots;

    Bus my_bus(capacity, fuel, cargo_slots);
    my_bus.display_info();

    double fuel_amount;
    std::cout << "Enter amount of fuel to add: ";
    std::cin >> fuel_amount;

    my_bus.refuel(fuel_amount);
    my_bus.display_info();

    // Adding cargo
    std::cout << "Adding cargo...\n";
    my_bus.add_cargo(Cargo::FOOD);
    my_bus.add_cargo(Cargo::LUGGAGE);
    my_bus.display_info();

    return 0;
}
