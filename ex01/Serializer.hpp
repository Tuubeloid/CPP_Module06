#pragma once
#include <cstdint>
#include <iostream>
#include "Data.hpp"

class Serializer {
    // Prevent instantiation by canonical form in private section
    private:
        Serializer() {}
        ~Serializer() {}
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);

    public:
        static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};