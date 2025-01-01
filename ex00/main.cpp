#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Incorrect number of arguments." << std::endl;
        std::cerr << "Usage: ./convert <value>" << std::endl;
        return 1;
    }
    std::cout << "Input in main: " << argv[1] << std::endl;
    ScalarConverter::convert(argv[1]);
    return 0;
}