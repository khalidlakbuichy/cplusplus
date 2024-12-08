#include "SerializationConverter.hpp"

// Canocical Form:
SerializationConverter::SerializationConverter() {}
SerializationConverter::SerializationConverter(SerializationConverter const &other) { 
    if (this != &other)
        *this = other; 
}
SerializationConverter &SerializationConverter::operator=(SerializationConverter const &other) {
    if (this != &other)
        *this = other;
    return *this; 
}
SerializationConverter::~SerializationConverter() {}

// static functions:
uintptr_t SerializationConverter::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *SerializationConverter::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}