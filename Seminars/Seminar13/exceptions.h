#pragma once

#include <exception>

class queue_is_empty_exception : public std::exception {
public:
    const char* what() const noexcept override {
        return "Queue is empty.";
    }
};

