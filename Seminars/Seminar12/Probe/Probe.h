#pragma once
#include "my_string.h"
#include "integer_vector.h"

struct Package {
    static int serial_number_ctr;
    int serial_number;
    int initial_size;

    Package(int size);
    virtual ~Package() = default;
    virtual Package* clone() const = 0;
  
    virtual void is_in_valid_state() const = 0;

    virtual my_string get_description() const;
};

struct MineralPackage : Package {
    my_string mineral_name;

    MineralPackage(const char* name, int size);
    Package* clone() const override;

    virtual void is_in_valid_state() const override;

    my_string get_description() const override;
};

struct LiquidPackage : Package {
    my_string liquid_name;
    double density;

    LiquidPackage(const char* name, double d, int size);
    Package* clone() const override;

    virtual void is_in_valid_state() const override;

    my_string get_description() const override;
};

class Probe {
    my_string name;
    Package** data;
    size_t size;
    size_t capacity;

    void copy_from(const Probe& other);
    void free();

    void resize();

public:
    Probe(const char* name);
    Probe(const Probe& other);
    Probe& operator=(const Probe& other);
    ~Probe();

    void add_package(Package* p);
    void remove_package(size_t index);
    void send_package(int index);

    void print() const;
};

