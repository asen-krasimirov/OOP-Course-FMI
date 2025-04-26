#include <iostream>

#include "my_string.h"

using namespace std;

int main() {

    my_string str1("Hello");
    my_string str2("Zero");

    str2 += "test";

    str2 += str2.c_str();

    bool is_str1_bigger = str1 > str2;

    cout << (str1 > str2) << endl;

    cout << "Bigger str: " << (is_str1_bigger ? str1 : str2) << endl;

    return 0;
}
