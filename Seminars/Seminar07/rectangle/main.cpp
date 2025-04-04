#include <iostream>
#include "rectangle.h"

int main() {
    double w, h;
    std::cout << "Enter width and height: ";
    std::cin >> w >> h;

    Rectangle rect(w, h);
    std::cout << "Area of the rectangle: " << rect.area() << std::endl;

    return 0;
}
