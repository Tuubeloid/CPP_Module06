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
    } else if (isValidCharLiteral(input)) {
        printCharLiteral(input);
        return ;
    } 
    size_t i = 0, dotCount = 0;
    if (input[i] == '+' || input[i] == '-') ++i;
    while (i < input.length() && (std::isdigit(input[i]) || input[i] == '.')) {
        if (input[i] == '.') ++dotCount;
        ++i;
    }
    if ((i < input.length() && std::isalpha(input[i])) || dotCount > 1) {
        std::cout << "Error: Invalid input" << std::endl;
        return ;
    }
    else if ((input[i] == 'f') && isValidFloatLiteral(input)) {
        printFloatLiteral(input);
        return ;
    } else if (isValidIntLiteral(input)) {
        printIntLiteral(input);
        return ;
    } else if (isValidDoubleLiteral(input)) {
        printDoubleLiteral(input);
        return ;
    } else {
        std::cout << "Error: Invalid input" << std::endl;
        return ;
    }
}
