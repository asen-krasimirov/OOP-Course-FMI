#include "Event.hpp"

template <typename T>
class MetricEvent : public Event<T> {
public:
    MetricEvent(const T& data);
    void print() const override;
    my_string serialize() const override;
    EventBase* clone() const override;
};

template<typename T>
MetricEvent<T>::MetricEvent(const T& data) : Event<T>(data) {}

template<typename T>
void MetricEvent<T>::print() const {
    cout << "Metric: ";
    Event<T>::print();
}

template<typename T>
my_string MetricEvent<T>::serialize() const {
    return "metric=<" + Event<T>::serialize() + ">";
}

template<typename T>
EventBase* MetricEvent<T>::clone() const {
    return new MetricEvent<T>(*this);
}
