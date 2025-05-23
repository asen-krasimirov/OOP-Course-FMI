#pragma once

#include "my_string.h"

class EventBase {
public:
    virtual void print() const = 0;
    virtual my_string serialize() const = 0;
    virtual EventBase* clone() const = 0;
    virtual ~EventBase() = default;
};
