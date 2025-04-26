#include <iostream>

#include "employee.h"

using namespace std;

Employee hire_full_time(const my_string& name);
Employee hire_intern(const my_string& name);
Employee hire_contractor(const my_string& name);

int main() {
    Employee e1 = hire_full_time("Alice");
    Employee e2 = hire_intern("Bob");
    Employee e3 = hire_contractor("Carol");
    Employee e4 = hire_full_time("Dave");

    std::cout << "\n--- Employee List ---\n";
    e1.show();
    e2.show();
    e3.show();
    e4.show();

    return 0;
}

