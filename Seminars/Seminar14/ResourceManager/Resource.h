#pragma once
#include "my_string.h"
#include <iostream>

class Resource {
    my_string name;
    int id;
    static int id_counter;

public:
    Resource(const my_string& n);
    ~Resource();

    void print() const;
};

int Resource::id_counter = 1;

Resource::Resource(const my_string& n) : name(n), id(id_counter++) {
    cout << "[Created] Resource '" << name << "' (ID: " << id << ")\n";
}

Resource::~Resource() {
    cout << "[Destroyed] Resource '" << name << "' (ID: " << id << ")\n";
}

void Resource::print() const {
    cout << "Resource: " << name << " (ID: " << id << ")\n";
}

