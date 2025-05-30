#pragma once

#include <utility> // for std::move, std::forward

template <typename T>
class my_unique_ptr {
private:
    T* ptr;

public:
    explicit my_unique_ptr(T* p = nullptr) : ptr(p) {}

    my_unique_ptr(const my_unique_ptr&) = delete;
    my_unique_ptr& operator=(const my_unique_ptr&) = delete;

    my_unique_ptr(my_unique_ptr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    my_unique_ptr& operator=(my_unique_ptr&& other) noexcept {
        if (this != &other) {
            delete ptr;

            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    ~my_unique_ptr() {
        delete ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* get() const {
        return ptr;
    }

    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void reset(T* p = nullptr) {
        if (ptr != p) {
            delete ptr;

            ptr = p;
        }
    }

    explicit operator bool() const {
        return ptr != nullptr;
    }
};

template <typename T, typename... Args>
my_unique_ptr<T> make_my_unique_ptr(Args&&... args) {
    return my_unique_ptr<T>(new T(std::forward<Args>(args)...));
}

