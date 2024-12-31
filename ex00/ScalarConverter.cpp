#include "ScalarConverter.hpp"
#include <string>
#include <cctype>
#include <iostream>
#include <stdexcept>

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

void ScalarConverter::CheckInput() {
    if (isSpecialLiteral(_input)) {
        // handle special literal
    }
    else if (isValidCharLiteral(_input)) {
        // handle char literal
    }
    else if (isValidIntLiteral(_input)) {
        // handle int literal
    }
    else if (isValidFloatLiteral(_input)) {
        // handle float literal
    }
    else if (isValidDoubleLiteral(_input)) {
        // handle double literal
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