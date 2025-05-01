#include <fstream>
#include <iostream>
#include <sstream>

#include "CSVNumbersFile.h"

CSVNumbersFile::CSVNumbersFile(const int* array, int n, const my_string& name) : NumbersFile(array, n, name) { }

void CSVNumbersFile::write_to_file() {
    ofstream out(file_name.c_str());
    
    if (!out) {
        cerr << "Error opening CSV file for writing.\n";
        return;
    }

    for (int i = 0; i < content.get_size(); ++i) {
        out << content[i];
        if (i != content.get_size() - 1) {
            out << ", ";
        }
    }

    out.close();
}

void CSVNumbersFile::read_from_file() {
    ifstream in(file_name.c_str());
    
    if (!in) {
        cerr << "Error opening CSV file for reading.\n";
        return;
    }

    int temp[1000];
    int count = 0;
    char delimiter;

    while (in >> temp[count]) {
        ++count;
        in.get(delimiter); // consume comma
        
        if (delimiter != ',' && delimiter != '\n') {
            break;
        }
        
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

