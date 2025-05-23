#include <iostream>

#include "EventContainer.hpp"

using namespace std;


int main() {
    EventContainer<10> container;

    container.add(LogEvent<my_string>("System started"));
    container.add(MetricEvent<int>(55));
    container.add(MetricEvent<my_string>("Disk I/O"));
    container.add(AlarmEvent<double>(91.2));

    const AlarmEvent<my_string> a("Disk full.");
    container.add(a);

    container.print_all();

    return 0;
}
