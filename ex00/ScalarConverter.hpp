#pragma once
#include <iostream>
#include <string>

class ScalarConverter {

	private:
		ScalarConverter();
		~ScalarConverter();

	public:
		ScalarConverter(std::string const & input);
		ScalarConverter & operator=(ScalarConverter & rhs);
		static void convert(const std::string& input);
};