#include "Employee.h"
#include <iostream>

int Employee::last_id = 1000;

Employee::Employee(const my_string& name) : name(name) {
    id = ++last_id;
}

void Employee::show() const {
    cout << "Name: " << name << ", ID: " << id << "\n";
}

int Employee::get_last_id() {
    return last_id;
}

Employee hire_full_time(const my_string& name) {
    static int full_time_count = 0;
    ++full_time_count;
    
    cout << "[Hired Full-Time #" << full_time_count << "] Name: " << name << "\n";
    
    return Employee(name);
}

Employee hire_intern(const my_string& name) {
    static int intern_count = 0;
    ++intern_count;
    
    cout << "[Hired Intern #" << intern_count << "] Name: " << name << "\n";
    
    return Employee(name);
}

Employee hire_contractor(const my_string& name) {
    static int contractor_count = 0;
    ++contractor_count;
    
    cout << "[Hired Contractor #" << contractor_count << "] Name: " << name << "\n";
    
    return Employee(name);
}

