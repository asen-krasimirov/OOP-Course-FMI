#pragma once

#include <sstream>

#include "EventBase.h"

using namespace std;

template <typename T>
class Event : public EventBase {
protected:
    T payload;
public:
    Event(const T& data);
    void print() const override;
    my_string serialize() const override;
    EventBase* clone() const override;
};

template <typename T>
Event<T>::Event(const T& data) : payload(data) {}

template <typename T>
void Event<T>::print() const {
    cout << "Event: " << payload << endl;
}

template <typename T>
my_string Event<T>::serialize() const {
    // Not learned.
    ostringstream oss;
    oss << payload;
    return oss.str().c_str();
}

template <typename T>
EventBase* Event<T>::clone() const {
    return new Event<T>(*this);
}

template <>
class Event<my_string> : public EventBase {
protected:
    my_string payload;
public:
    Event(const my_string& data);
    void print() const override;
    my_string serialize() const override;
    EventBase* clone() const override;
};

Event<my_string>::Event(const my_string& data) : payload(data) {}

void Event<my_string>::print() const {
    cout << "Event: \"" << payload << "\"" << endl;
}

my_string Event<my_string>::serialize() const {
    return "\"" + payload + "\"";
}

EventBase* Event<my_string>::clone() const {
    return new Event<my_string>(*this);
}
