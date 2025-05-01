#include <fstream>
#include <iostream>

#include "BinaryNumbersFile.h"

BinaryNumbersFile::BinaryNumbersFile(const int* array, int n, const my_string& name) : NumbersFile(array, n, name) {}

void BinaryNumbersFile::write_to_file() {
    ofstream out(file_name.c_str(), ios::binary);
    
    if (!out) {
        std::cerr << "Error opening binary file for writing.\n";
        return;
    }

    for (int i = 0; i < content.get_size(); ++i) {
        out.write((char*)(&content[i]), sizeof(int));
    }

    out.close();
}

void BinaryNumbersFile::read_from_file() {
    ifstream in(file_name.c_str(), ios::binary);
    
    if (!in) {
        cerr << "Error opening binary file for reading.\n";
        return;
    }

    int temp[1000];
    int count = 0;

    while (in.read((char*)(&temp[count]), sizeof(int))) {
        ++count;

        if (count >= 1000) {
            break; // avoid overflow
        }
    }

    content.clear();

    for (int i = 0; i < count; ++i) {
        content.push_back(temp[i]);
    }

    in.close();
}
