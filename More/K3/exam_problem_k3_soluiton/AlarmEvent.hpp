#include "Event.hpp"

template <typename T>
class AlarmEvent : public Event<T> {
public:
    AlarmEvent(const T& data);
    void print() const override;
    my_string serialize() const override;
    EventBase* clone() const override;
};

template<typename T>
AlarmEvent<T>::AlarmEvent(const T& data) : Event<T>(data) {}

template<typename T>
void AlarmEvent<T>::print() const {
    cout << "ALARM: ";
    Event<T>::print();
}

template<typename T>
my_string AlarmEvent<T>::serialize() const {
    return "ALARM=<" + Event<T>::serialize() + ">";
}

template<typename T>
EventBase* AlarmEvent<T>::clone() const {
    return new AlarmEvent<T>(*this);
}
