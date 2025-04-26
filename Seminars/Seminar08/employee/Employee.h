#pragma once

#include "my_string.h"

class Employee {
    my_string name;
    int id;
    static int last_id;

public:
    Employee(const my_string& name);
    void show() const;

    static int get_last_id();
};

