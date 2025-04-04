#include <iostream>

class Bus {
private:
    int capacity;

public:
    Bus(int cap) { capacity = cap; }

    // Declare friend function
    friend void show_capacity(const Bus& b);
};

// Friend function definition (not a member of Bus)
void show_capacity(const Bus& b) {
    std::cout << "Bus capacity: " << b.capacity << " passengers\n";
}

int main() {
    Bus my_bus(50);
    show_capacity(my_bus);  // Accesses private capacity
    return 0;
}
