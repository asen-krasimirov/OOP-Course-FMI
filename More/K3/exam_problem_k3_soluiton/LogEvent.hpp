#include "Event.hpp"

template <typename T>
class LogEvent : public Event<T> {
public:
    LogEvent(const T& data);
    void print() const override;
    my_string serialize() const override;
    EventBase* clone() const override;
};

template<typename T>
LogEvent<T>::LogEvent(const T& data) : Event<T>(data) {}

template<typename T>
void LogEvent<T>::print() const {
    cout << "Log: ";
    Event<T>::print();
}

template<typename T>
my_string LogEvent<T>::serialize() const {
    return "log=<" + Event<T>::serialize() + ">";
}

template<typename T>
EventBase* LogEvent<T>::clone() const {
    return new LogEvent<T>(*this);
}
