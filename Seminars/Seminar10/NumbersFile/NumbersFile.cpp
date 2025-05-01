#include "NumbersFile.h"
#include <fstream>
#include <iostream>

NumbersFile::NumbersFile(const int* array, int n, const my_string& name) : file_name(name) {
    for (int i = 0; i < n; ++i) {
        content.push_back(array[i]);
    }
}

void NumbersFile::write_to_file() {
    ofstream out(file_name.c_str());

    if (!out) {
        std::cerr << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i < content.get_size(); ++i) {
        out << content[i];
    }
    
    out.close();
}

void NumbersFile::read_from_file() {
    ifstream in(file_name.c_str());
    
    if (!in) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    int temp[1000];
    int count = 0;

    while (in >> temp[count]) {
        ++count;
        if (count >= 1000) break;  // avoid overflow
    }

    content.clear();

    for (int i = 0; i < count; ++i) {
        content.push_back(temp[i]);
    }

    in.close();
}

void NumbersFile::add_number(int number) {
    content.push_back(number);
}

void NumbersFile::remove_number(int index) {
    if (index >= 0 && index < content.get_size()) {
        content.remove_at(index);
    }
    else {
        cerr << "Invalid index for removal." << endl;
    }
}

void NumbersFile::sort() {
    content.sort();
}

void NumbersFile::print() const {
    for (int i = 0; i < content.get_size(); ++i) {
        cout << content[i] << " ";
    }
    
    cout << endl;
}

