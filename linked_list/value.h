#ifndef VALUE_H
#define VALUE_H

#include <iostream>
#include "node_abstraction.h"

template <typename T>
class Value : public IElement
{
private:
    T value_;
public:
    Value() = default;
    Value(T value) : value_(value) {}
    T get_value() { return value_; }
    void set_value(T value) { value_ = value; }
    ~Value() = default;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Value<T>& val)
{
    out << val.get_value();
    return out;
}

#endif // VALUE_H
