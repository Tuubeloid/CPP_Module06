#pragma once
#include <iostream>
#include <string>

class ScalarConverter {

	private:
		std::string _input;
		ScalarConverter();
		~ScalarConverter();

	public:
		ScalarConverter(std::string const & input);
		ScalarConverter & operator=(ScalarConverter & rhs);
		void ScalarConverter::CheckInput();
};