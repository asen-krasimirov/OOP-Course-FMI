#pragma once
#include <exception>
#include <string>

class invalid_probe_name_exception : public exception {
public:
    const char* what() const noexcept override {
        return "Probe name cannot be empty!";
    }
};

class invalid_mineral_exception : public invalid_argument {
public:
    invalid_mineral_exception(const my_string& mineral)
        : invalid_argument(("Invalid mineral: " + mineral).c_str()) {}
};

class invalid_density_exception : public invalid_argument {
public:
    invalid_density_exception()
        : invalid_argument("Invalid liquid density.") {}
};

class cannot_remove_last_package_exception : public logic_error {
public:
    cannot_remove_last_package_exception()
        : logic_error("Cannot remove last package from probe.") {}
};

class invalid_probe_name_exception : public invalid_argument {
public:
    invalid_probe_name_exception(const my_string& name)
        : invalid_argument(("Probe name must end with 'AA': " + name).c_str()) {}
};
