#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
#include <locale>
#include <cstdlib>
#include <string>
#include <stack>

class RPN
{
	public:
	
		RPN(void);
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN(void);

		void calculator(const std::string &str);
		void selectOperation(const char oprt);

	private:

		std::stack<double> _stack;
};

# endif