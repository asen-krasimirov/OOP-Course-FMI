#pragma once

#include <exception>

#include "EventBase.h"

#include "LogEvent.hpp"
#include "MetricEvent.hpp"
#include "AlarmEvent.hpp"

using namespace std;

template <const size_t capacity>
class EventContainer {
    EventBase** events;
    size_t size;
    //size_t capacity;

    void free();
    void copy_from(const EventContainer& other);
    void resize();

public:
    EventContainer();
    EventContainer(const EventContainer& other);
    EventContainer& operator=(const EventContainer& other);
    ~EventContainer();

    void add(const EventBase &e);
    
    void pop();

    void print_all() const;
};


template <const size_t capacity>
void EventContainer<capacity>::free() {
    for (size_t i = 0; i < size; ++i) {
        delete events[i];
    }

    delete[] events;
    events = nullptr;
    size = 0;
    //capacity = 0;
}

template <const size_t capacity>
void EventContainer<capacity>::copy_from(const EventContainer<capacity>& other) {
    size = other.size;
    //capacity = other.capacity;

    events = new EventBase * [capacity];
    for (size_t i = 0; i < size; ++i) {
        events[i] = other.events[i]->clone();
    }
}

template <const size_t capacity>
void EventContainer<capacity>::resize() {
    //capacity = (capacity == 0) ? 4 : capacity * 2;

    EventBase** new_array = new EventBase * [capacity];

    for (size_t i = 0; i < size; ++i) {
        new_array[i] = events[i];
    }

    delete[] events;
    events = new_array;
}

template <const size_t capacity>
EventContainer<capacity>::EventContainer() : events(new EventBase* [capacity]), size(0) {}

template <const size_t capacity>
EventContainer<capacity>::EventContainer(const EventContainer<capacity>& other) {
    copy_from(other);
}

template <const size_t capacity>
EventContainer<capacity>& EventContainer<capacity>::operator=(const EventContainer<capacity>& other) {
    if (this != &other) {
        free();
        copy_from(other);
    }

    return *this;
}

template <const size_t capacity>
EventContainer<capacity>::~EventContainer() {
    free();
}

template <const size_t capacity>
void EventContainer<capacity>::add(const EventBase& e) {
    if (size == capacity) {
        throw out_of_range("Max capacity reached.");
    }

    events[size++] = e.clone();
}

template <const size_t capacity>
void EventContainer<capacity>::pop() {
    if (size == 0) {
        throw logic_error("The container is empty.");
    }

    size--;
}

template<size_t capacity>
void EventContainer<capacity>::print_all() const {
    for (size_t i = 0; i < size; ++i) {
        events[i]->print();
        cout << "Serialized: " << events[i]->serialize() << endl;
    }
}
