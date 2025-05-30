#include <iostream>
#include <stdexcept>

template <typename T>
class my_vector {
private:
    T* data;
    int capacity;
    int length;

    void resize(int new_capacity) {
        T* new_data = new T[new_capacity];

        for (int i = 0; i < length; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;

        capacity = new_capacity;
    }

    void free() {
        delete[] data;
        data = nullptr;
        capacity = 0;
        length = 0;
    }

    void copy_from(const my_vector<T>& other) {
        capacity = other.capacity;
        length = other.length;
        data = new T[capacity];
        
        for (int i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }

public:
    my_vector() : data(nullptr), capacity(0), length(0) {}

    my_vector(const my_vector<T>& other) : data(nullptr), capacity(0), length(0) {
        copy_from(other);
    }

    my_vector<T>& operator=(const my_vector<T>& other) {
        if (this != &other) {
            free();
            copy_from(other);
        }

        return *this;
    }

    ~my_vector() {
        free();
    }

    void push_back(const T& value) {
        if (length == capacity) {
            resize(capacity == 0 ? 4 : capacity * 2);
        }

        data[length++] = value;
    }

    T& operator[](int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds");
        }

        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds");
        }

        return data[index];
    }

    int size() const {
        return length;
    }

    int get_capacity() const {
        return capacity;
    }
};

