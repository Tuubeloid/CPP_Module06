#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <limits>
#include <cfloat>
#include <cmath>

class ScalarConverter {
    // Prevent instantiation by canonical form in private section
    private:
        ScalarConverter() {}
        ~ScalarConverter() {}
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);

    public:
        static void convert(const std::string& input);
};