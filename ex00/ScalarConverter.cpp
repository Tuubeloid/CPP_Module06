#include "ScalarConverter.hpp"

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

bool isNonDisplayable(const std::string& input) {
    std::cout << "Inside displayable check" << std::endl;
    if (input == "+nan" || input == "-nan" ||
        input == "+nanf" || input == "-nanf") {
            return false;
    }
    if (input.length() == 1) {
        return std::isprint(input[0]);
    }
    bool containsOnlyAlpha = true;
    for (size_t i = 0; i < input.length(); ++i) {
        if (!std::isalpha(input[i])) {
            containsOnlyAlpha = false;
            break;
        }
    }
    std::cout << containsOnlyAlpha << std::endl << input.length() << std::endl;
    if (containsOnlyAlpha && input.length() > 1) {
        return false;
    }
    return true;
}

bool isSpecialLiteral(const std::string& input) {
    std::cout << "inside special literal check" << std::endl;
    return input == "nan" || input == "nanf" ||
           input == "-inf" || input == "+inf" ||
           input == "inf" || input == "inff" ||
           input == "-inff" || input == "+inff";
}

void printCharLiteral(const std::string& input) {
    char c = input[0];

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

bool isValidCharLiteral(const std::string& input) {

    std::cout << "input: " << input << std::endl;

    std::cout << "length of input: " << input.length() << std::endl;
    if (input.length() > 1) { 
        std::cout << "length of input is greater than 1" << std::endl;
        return false;
    }
    if (std::isprint(input[0]) && !std::isdigit(input[0])) {
        printCharLiteral(input);
        return true;
    }
    std::cout << "returning false" << std::endl;
    return false;
}

bool isValidIntLiteral(const std::string& input) {
    std::cout << "Inside int validator"<< std::endl;
    size_t i = 0;
    if (input[i] == '+' || input[i] == '-') ++i;
    while (i < input.length() && std::isdigit(input[i])) ++i;
    return i == input.length();
}

bool isValidFloatLiteral(const std::string& input) {
    std::cout << "Inside float validator"<< std::endl;
    size_t i = 0, dotCount = 0;
    if (input[i] == '+' || input[i] == '-') ++i;
    while (i < input.length() && (std::isdigit(input[i]) || input[i] == '.')) {
        if (input[i] == '.') ++dotCount;
        ++i;
    }
    return dotCount <= 1 && input.back() == 'f';
}

bool isValidDoubleLiteral(const std::string& input) {
    std::cout << "Inside double validator"<< std::endl;
    size_t i = 0, dotCount = 0;
    if (input[i] == '+' || input[i] == '-') ++i;
    while (i < input.length() && (std::isdigit(input[i]) || input[i] == '.')) {
        if (input[i] == '.') ++dotCount;
        ++i;
    }
    return dotCount <= 1;
}

void printSpecialLiteral(const std::string& input) {
    std::cout << "printing special literal" << std::endl;
    if (input == "nan" || input == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (input == "-inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (input == "+inf" || input == "inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
    else if (input == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (input == "+inff" || input == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
}

void printIntLiteral(const std::string& input) {
    std::cout << "printing int literal" << std::endl;
    try {
        int value = std::stoi(input);
        if (value < 32 || value > 126) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        }
        std::cout << "int: " << value << std::endl;
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void printFloatLiteral(const std::string& input) {
    std::cout << "printing float literal" << std::endl;
    try {
        float value = std::stof(input);
        if (std::isinf(value)) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << input << std::endl;
            std::cout << "double: " << static_cast<double>(value) << std::endl;
        } else if (std::isnan(value)) {
            printSpecialLiteral(input);
        } else {
            if (value < 32 || value > 126) {
                std::cout << "char: Non displayable" << std::endl;
            } else {
                std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
            }
            std::cout << "int: " << static_cast<int>(value) << std::endl;
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << value << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(value) << std::endl;
        }
    } catch (const std::out_of_range&) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void printDoubleLiteral(const std::string& input) {
    std::cout << "printing double literal" << std::endl;
    try {
        double value = std::stod(input);
        if (std::isinf(value)) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
            std::cout << "double: " << value << std::endl;
        } else if (std::isnan(value)) {
            printSpecialLiteral(input);
        } else {
            if (value < 32 || value > 126) {
                std::cout << "char: Non displayable" << std::endl;
            } else {
                std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
            }
            std::cout << "int: " << static_cast<int>(value) << std::endl;
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
            std::cout << "double: " << value << std::endl;
        }
    } catch (const std::out_of_range&) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::convert(const std::string& input) {
    if (isSpecialLiteral(input)) {
        printSpecialLiteral(input);
        return ;
    }
     else if (!isNonDisplayable(input)) {
        std::cout << "Error: Invalid input 0" << std::endl;
        return ;
    }
     else if (isValidCharLiteral(input)) {
        return ;
    }
     else if (isValidIntLiteral(input)) {
         printIntLiteral(input);
         return ;
    }
    size_t i = 0, dotCount = 0, strlen = input.length(), fCount = 0;
    if (input[i] == '+' || input[i] == '-') ++i;
    while (i < strlen && (std::isdigit(input[i]) || input[i] == '.')) {
        if (input[i] == '.') ++dotCount;
        else if (input[i] == 'f') ++fCount;
        i++;
    }
    if (std::isalpha(input.back()) && input.back() != 'f') {
        std::cout << "Error: Invalid input 1" << std::endl;
        return ;
    }
    if (isValidDoubleLiteral(input)) {
        printDoubleLiteral(input);
        return ;
    }
    if ((input.back() == 'f') && isValidFloatLiteral(input)) {
        printFloatLiteral(input);
        return ;
    }
    else {
        std::cout << "Error: Invalid input 2" << std::endl;
        return ;
    }
}
