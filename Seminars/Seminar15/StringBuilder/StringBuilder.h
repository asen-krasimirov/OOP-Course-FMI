#pragma once


#include <iostream>
#include "my_string.h"

class StringBuilder {
private:
    my_string buffer;

public:
    StringBuilder& append(const my_string& str) {
        buffer += str;
        return *this;
    }

    StringBuilder& clear() {
        buffer = "";
        return *this;
    }

    my_string to_string() const {
        return buffer;
    }

    size_t length() const {
        return buffer.get_length();
    }

    bool empty() const {
        return buffer == "";
    }
};

