#include <iostream>
#include <stdexcept>

#include "probe.h"
#include "exceptions.h"

int Package::serial_number_ctr = 0;

Package::Package(int size) : initial_size(size) {
    serial_number = ++serial_number_ctr;
}

my_string Package::get_description() const {
    return "Generic Package";
}

MineralPackage::MineralPackage(const char* name, int size)
    : Package(size), mineral_name(name) {}

Package* MineralPackage::clone() const {
    return new MineralPackage(mineral_name.c_str(), initial_size);
}

void MineralPackage::is_in_valid_state() const {
    if (mineral_name == "Iron" || mineral_name == "Gold" || mineral_name == "Titanium") {
        return;
    }

    throw invalid_mineral_exception(mineral_name);
}

my_string MineralPackage::get_description() const {
    return "Mineral Package: " + mineral_name;
}

LiquidPackage::LiquidPackage(const char* name, double d, int size)
    : Package(size), liquid_name(name), density(d) {}

Package* LiquidPackage::clone() const {
    return new LiquidPackage(liquid_name.c_str(), density, initial_size);
}

void LiquidPackage::is_in_valid_state() const {
    if (density < 0.5 || density > 2.5) {
        throw invalid_density_exception();
    }
}

my_string LiquidPackage::get_description() const {
    return "Liquid Package: " + liquid_name;
}

void Probe::free() {
    for (size_t i = 0; i < size; ++i) {
        delete data[i];
    }

    delete[] data;
    data = nullptr;
    
    size = 0;
    capacity = 0;
}

void Probe::resize() {
    size_t new_cap = capacity * 2;
    Package** new_data = new Package * [new_cap];

    for (size_t i = 0; i < size; ++i) {
        new_data[i] = data[i];
    }

    free();

    data = new_data;
    capacity = new_cap;
}

void Probe::copy_from(const Probe& other) {
    name = other.name;
    size = other.size;
    capacity = other.capacity;

    data = new Package * [capacity];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i]->clone();
    }
}

Probe::Probe(const char* probe_name) : name(probe_name), size(0), capacity(2) {

    size_t len = name.get_length();

    if (len < 2 || name[len - 2] != 'A' || name[len - 1] != 'A') {
        throw invalid_probe_name_exception(name.c_str());
    }

    data = new Package * [capacity];
}

Probe::Probe(const Probe& other) {
    copy_from(other);
}

Probe& Probe::operator=(const Probe& other) {
    if (this != &other) {
        free();
        copy_from(other);
    }

    return *this;
}

Probe::~Probe() {
    free();
}

void Probe::add_package(Package* p) {
    if (!p) {
        throw invalid_argument("Can not add null package.");
    }

    p->is_in_valid_state();

    if (size == capacity) {
        resize();
    }

    data[size++] = p;
}

void Probe::remove_package(size_t index) {
    if (index >= size) {
        throw out_of_range("Invalid index");
    }

    if (size <= 1) {
        throw cannot_remove_last_package_exception();
    }

    delete data[index];
    
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }

    --size;
}

void Probe::send_package(int index) {
    if (index < 0 || index >= size) {
        throw invalid_argument("Invalid package index.");
    }
    
    remove_package(index);

    Package* pkg = data[index];

    cout << "=== Sending Package #" << pkg->serial_number << " ===" << endl;
    cout << "Description: " << pkg->get_description() << endl;
    cout << "Initiating in-flight analysis..." << endl;
    cout << "Package sent successfully." << endl << endl;
}
void Probe::print() const {
    cout << "Cargo descriptions: " << endl;

    for (int i = 0; i < size; ++i) {
        cout << data[i]->get_description() << endl;
    }
}

