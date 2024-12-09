#include "SerializationConverter.hpp"

int main(void)
{
	Data data = 42;
	uintptr_t serialized = SerializationConverter::serialize(&data);
	Data *deserialized = SerializationConverter::deserialize(serialized);

	std::cout << "Data: " << *deserialized << std::endl;

	return 0;
}