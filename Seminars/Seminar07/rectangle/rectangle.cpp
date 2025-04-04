#include "rectangle.h"

Rectangle::Rectangle(double w, double h) {
    width = w;
    height = h;
}

double Rectangle::area() {
    return width * height;
}
