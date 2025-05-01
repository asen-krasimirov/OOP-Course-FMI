#pragma once

#include "NumbersFile.h"

class CSVNumbersFile : public NumbersFile {
public:
    CSVNumbersFile(const int* array, int n, const my_string& name);

    void write_to_file() override;
    void read_from_file() override;
};

