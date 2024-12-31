#include "ScalarConverter.hpp"
#include <string>
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <climits>
#include <cfloat>

/*
  Use appropriate functions to parse and handle the input, such as std::stoi for integers, 
  std::stof for floats, and std::stod for doubles.

  +inf and +inff (Positive Infinity):
  -inf and -inff (Negative Infinity):
  nan and nanf (Not-a-Number):
  These values are part of the IEEE 754 floating-point specification and are supported by C++.
  You can check for them using standard library functions:
  std::isinf(value) checks if a value is infinite (+inf or -inf).
  std::isnan(value) checks if a value is nan.
*/

bool isSpecialLiteral(const std::string& input) {
    return input == "nan" || input == "nanf" ||
           input == "-inf" || input == "+inf" ||
           input == "-inff" || input == "+inff";
}

bool isValidCharLiteral(const std::string& input) {
    return input.length() == 3 && input[0] == '\'' && input[2] == '\'' && isprint(input[1]);
}

bool isValidIntLiteral(const std::string& input) {
    size_t i = 0;
    if (input[i] == '+' || input[i] == '-') ++i;
    while (i < input.length() && std::isdigit(input[i])) ++i;
    return i == input.length();
}

bool isValidFloatLiteral(const std::string& input) {
    size_t i = 0, dotCount = 0;
    if (input[i] == '+' || input[i] == '-') ++i;
    while (i < input.length() && (std::isdigit(input[i]) || input[i] == '.')) {
        if (input[i] == '.') ++dotCount;
        ++i;
    }
    return dotCount <= 1 && input.back() == 'f';
}

bool isValidDoubleLiteral(const std::string& input) {
    size_t i = 0, dotCount = 0;
    if (input[i] == '+' || input[i] == '-') ++i;
    while (i < input.length() && (std::isdigit(input[i]) || input[i] == '.')) {
        if (input[i] == '.') ++dotCount;
        ++i;
    }
    return dotCount <= 1;
}

void printSpecialLiteral(const std::string& input) {
    if (input == "nan" || input == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
    }
}

void printCharLiteral(const std::string& input) {
    char c = input[1];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void printIntLiteral(const std::string& input) {
    int i = std::stoi(input);
    std::cout << "char: ";
    if (std::isprint(i)) {
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void printFloatLiteral(const std::string& input) {
    float f = std::stof(input);
    std::cout << "char: ";
    if (std::isprint(f)) {
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }
    std::cout << "int: ";
    if (f >= INT_MIN && f <= INT_MAX) {
        std::cout << static_cast<int>(f) << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void printDoubleLiteral(const std::string& input) {
    double d = std::stod(input);
    std::cout << "char: ";
    if (std::isprint(d)) {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }
    std::cout << "int: ";
    if (d >= INT_MIN && d <= INT_MAX) {
        std::cout << static_cast<int>(d) << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "float: ";
    if (d >= -FLT_MAX && d <= FLT_MAX) {
        std::cout << static_cast<float>(d) << "f" << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "double: " << d << std::endl;
}

static void convert(const std::string& input) {
    if (isSpecialLiteral(input)) {
        printSpecialLiteral(input);
    }
    else if (isValidCharLiteral(input)) {
        printCharLiteral(input);
    }
    else if (isValidIntLiteral(input)) {
        printIntLiteral(input);
    }
    else if (isValidFloatLiteral(input)) {
        printFloatLiteral(input);
    }
    else if (isValidDoubleLiteral(input)) {
        printDoubleLiteral(input);
    }
    else {
        throw std::invalid_argument("Invalid input literal.");
    }
}

/*void ScalarConverter::CheckInput() {
    if (isSpecialLiteral(_input) || isValidCharLiteral(_input) || isValidIntLiteral(_input) ||
        isValidFloatLiteral(_input) || isValidDoubleLiteral(_input)) {
        std::cout << "Input is valid." << std::endl;
    } else {
        throw std::invalid_argument("Invalid input literal.");
    }
}*/