#include <iostream>

#include "NumbersFile.h"
#include "CSVNumbersFile.h"
#include "BinaryNumbersFile.h"
#include "my_string.h"
#include <iostream>

int main() {
    int data[] = { 10, 5, 30, 20, 15 };
    int size = sizeof(data) / sizeof(data[0]);

    my_string name_txt("numbers.txt");
    my_string name_csv("numbers.csv");
    my_string name_bin("numbers.bin");

    // Using plain text file with NumberFile
    NumbersFile text_file(data, size, name_txt);
    text_file.sort();
    text_file.write_to_file();

    std::cout << "Text file content after write: ";
    text_file.print();

    text_file.read_from_file();
    std::cout << "Text file content after read: ";
    text_file.print();

    // Using CSV format
    CSVNumbersFile csv_file(data, size, name_csv);
    csv_file.add_number(42);
    csv_file.sort();
    csv_file.write_to_file();

    std::cout << "CSV file content after write: ";
    csv_file.print();

    csv_file.read_from_file();
    std::cout << "CSV file content after read: ";
    csv_file.print();

    // Using binary format
    BinaryNumbersFile binary_file(data, size, name_bin);
    binary_file.remove_number(1); // remove index 1
    binary_file.write_to_file();

    std::cout << "Binary file content after write: ";
    binary_file.print();

    binary_file.read_from_file();
    std::cout << "Binary file content after read: ";
    binary_file.print();

    return 0;
}

