#pragma once
#include <iostream>
#include <string>

class ScalarConverter {

	private:
		std::string _input;
		ScalarConverter();
		~ScalarConverter();

	public:
		ScalarConverter(std::string const & literal);
		ScalarConverter & operator=(ScalarConverter & rhs);
};