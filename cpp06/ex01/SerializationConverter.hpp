#include <iostream>
#include <string>
#include <cstdint>

#ifndef SERIALIZATIONCONVERTER_HPP
#define SERIALIZATIONCONVERTER_HPP

typedef int Data;

class SerializationConverter
{
    private:
        SerializationConverter();
        SerializationConverter(SerializationConverter const &other);
        SerializationConverter &operator=(SerializationConverter const &other);
        ~SerializationConverter();


    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif