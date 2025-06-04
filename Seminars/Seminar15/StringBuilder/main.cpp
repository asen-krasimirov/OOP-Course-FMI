#include <iostream>

#include "StringBuilder.h"

using namespace std;

int main() {
    StringBuilder sb;

    sb.append("Hello")
        .append(", ")
        .append("World")
        .append("!");

    cout << "Result: " << sb.to_string() << endl;  // Hello amazing, World!

    sb.clear();
    
    cout << "After clear: " << sb.to_string() << endl;  // empty

    return 0;
}

