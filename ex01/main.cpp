#include "Serializer.hpp"

int main() {
	Data data;
	data.str1 = "Hello";
	data.str2 = "World";
	data.number = 42;

	uintptr_t serialized = Serializer::serialize(&data);
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Original data:" << std::endl;
	std::cout << "str1: " << data.str1 << std::endl;
	std::cout << "str2: " << data.str2 << std::endl;
	std::cout << "number: " << data.number << std::endl;

	std::cout << "Deserialized data:" << std::endl;
	std::cout << "str1: " << deserialized->str1 << std::endl;
	std::cout << "str2: " << deserialized->str2 << std::endl;
	std::cout << "number: " << deserialized->number << std::endl;

	return 0;
}