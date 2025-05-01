#include "integer_vector.h"
#include "my_string.h"

class NumbersFile {
protected:
    integer_vector content;
    my_string file_name;

public:
    NumbersFile(const int* array, int n, const my_string& name);

    virtual void write_to_file();
    virtual void read_from_file();
    
    void add_number(int number);
    void remove_number(int index);
    
    void sort();
    void print() const;
};

