#pragma once

#include <iostream>

enum class Cargo {
    NONE,
    LUGGAGE,
    FOOD,
    ELECTRONICS,
    CHEMICALS
};

class Bus {
private:
    int capacity;
    int cargo_count;
    Cargo* cargo_list; // Dynamic array for cargo
    double fuel_level;

public:
    // Constructor
    Bus(int cap, double fuel, int cargo_slots);

    // Destructor
    ~Bus();

    // Copy Constructor (Deep Copy)
    Bus(const Bus& other);

    // Copy Assignment Operator (Deep Copy)
    Bus& operator=(const Bus& other);

    // Member functions
    void refuel(double amount);
    void display_info();
    void add_cargo(Cargo cargo);
};
