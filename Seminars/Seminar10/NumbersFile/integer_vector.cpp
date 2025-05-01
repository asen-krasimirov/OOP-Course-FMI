#include "integer_vector.h"
#include <algorithm>
#include <iostream>

namespace {
    void custom_swap(int& n1, int& n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
}

integer_vector::integer_vector() : data(nullptr), size(0), capacity(0) {}

integer_vector::integer_vector(const integer_vector& other) {
    copy_from(other);
}

integer_vector& integer_vector::operator=(const integer_vector& other) {
    if (this != &other) {
        free();
        copy_from(other);
    }

    return *this;
}

integer_vector::~integer_vector() {
    free();
}

void integer_vector::free() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

void integer_vector::copy_from(const integer_vector& other) {
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

void integer_vector::resize(int new_capacity) {
    int* new_data = new int[new_capacity];
    
    for (int i = 0; i < size; ++i) {
        new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

void integer_vector::push_back(int value) {
    if (size >= capacity) {
        resize(capacity == 0 ? 4 : capacity * 2);
    }

    data[size++] = value;
}

void integer_vector::remove_at(int index) {
    if (index < 0 || index >= size) {
        return;
    }
    
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    
    --size;
}

int& integer_vector::operator[](int index) {
    return data[index];
}

const int& integer_vector::operator[](int index) const {
    return data[index];
}

int integer_vector::get_size() const {
    return size;
}

void integer_vector::clear() {
    free();
}

void integer_vector::sort() {
    for (int i = 0; i < size - 1; ++i) {
        int min_index = i;

        for (int j = i + 1; j < size; ++j) {
            if (data[j] < data[min_index]) {
                min_index = j;
            }

        }

        custom_swap(data[i], data[min_index]);
    }
}

int* integer_vector::raw_data() {
    return data;
}

