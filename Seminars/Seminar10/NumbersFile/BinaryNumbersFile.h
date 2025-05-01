#pragma once

#include "NumbersFile.h"

class BinaryNumbersFile : public NumbersFile {
public:
    BinaryNumbersFile(const int* array, int n, const my_string& name);

    void write_to_file() override;
    void read_from_file() override;
};

