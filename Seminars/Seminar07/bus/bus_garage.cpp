#include <iostream>

class Bus {
private:
    int capacity;

public:
    Bus(int cap) { capacity = cap; }

    // Declare Garage as a friend class
    friend class Garage;
};

class Garage {
public:
    void increase_capacity(Bus& b, int amount) {
        b.capacity += amount;  // Directly modifying private member
        std::cout << "Bus capacity increased to: " << b.capacity << "\n";
    }
};

int main() {
    Bus my_bus(50);
    Garage my_garage;

    my_garage.increase_capacity(my_bus, 10); // Increases capacity
    return 0;
}
