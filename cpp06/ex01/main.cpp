#include "SerializationConverter.hpp"

int main(void)
{
	Data data = -1234;
	Data data2 = 42;

	// Serializer s;
	uintptr_t raw = SerializationConverter::serialize(&data);
	Data* ptr = SerializationConverter::deserialize(raw);
	
	*SerializationConverter::deserialize(SerializationConverter::serialize(&data2)) = 1337;

	std::cout << *ptr << std::endl;
	std::cout << data2 << std::endl;
	return 0;
}