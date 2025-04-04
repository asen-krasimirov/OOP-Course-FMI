#include "bus.h"

// Constructor
Bus::Bus(int cap, double fuel, int cargo_slots) {
    capacity = cap;
    fuel_level = fuel;
    cargo_count = cargo_slots;
    cargo_list = new Cargo[cargo_count];

    for (int i = 0; i < cargo_count; i++) {
        cargo_list[i] = Cargo::NONE;
    }
}

// Destructor
Bus::~Bus() {
    delete[] cargo_list;
}

// Copy Constructor
Bus::Bus(const Bus& other) {
    capacity = other.capacity;
    fuel_level = other.fuel_level;
    cargo_count = other.cargo_count;

    cargo_list = new Cargo[cargo_count];
    for (int i = 0; i < cargo_count; i++) {
        cargo_list[i] = other.cargo_list[i];
    }
}

// Copy Assignment Operator
Bus& Bus::operator=(const Bus& other) {
    if (this != &other) { // Self-assignment check
        delete[] cargo_list; // Free existing memory

        capacity = other.capacity;
        fuel_level = other.fuel_level;
        cargo_count = other.cargo_count;

        cargo_list = new Cargo[cargo_count];
        for (int i = 0; i < cargo_count; i++) {
            cargo_list[i] = other.cargo_list[i];
        }
    }
    return *this;
}

// Refuel method
void Bus::refuel(double amount) {
    fuel_level += amount;
    std::cout << "Bus refueled. New fuel level: " << fuel_level << " liters\n";
}

// Display Bus Info
void Bus::display_info() {
    std::cout << "Bus capacity: " << capacity << " passengers\n";
    std::cout << "Current fuel level: " << fuel_level << " liters\n";
    std::cout << "Cargo slots: " << cargo_count << "\n";
    std::cout << "Cargo: ";
    for (int i = 0; i < cargo_count; i++) {
        std::cout << static_cast<int>(cargo_list[i]) << " ";
    }
    std::cout << "\n";
}

// Add Cargo
void Bus::add_cargo(Cargo cargo) {
    for (int i = 0; i < cargo_count; i++) {
        if (cargo_list[i] == Cargo::NONE) {
            cargo_list[i] = cargo;
            std::cout << "Cargo added.\n";
            return;
        }
    }
    std::cout << "No space for more cargo!\n";
}
