# include "RPN.hpp"

RPN::RPN(void)	{}
RPN::RPN(const RPN &src)	{(void) src;}
RPN &RPN::operator=(const RPN &src)	{(void) src; return(*this);}
RPN::~RPN(void)	{}


void RPN::selectOperation(const char c)
{
	int operat;
	double firstOperand;
	double secondOperand;
	double result;


	std::cout << "_" << c << "_\n";
	if (_stack.size() < 2)
		throw std::exception();
	operat = c;
	
	secondOperand = _stack.top();
	_stack.pop();
	firstOperand = _stack.top();
	_stack.pop();

	std::cout << "operator: " << operat << std::endl;

	switch (operat)
	{
	case '+':
			std::cout << firstOperand << " + " << secondOperand << std::endl;
			result = firstOperand + secondOperand;
		break;
	
	case '-':
			std::cout << firstOperand << " - " << secondOperand << std::endl;
			result = firstOperand - secondOperand;
		break;
	
	case '*':
			std::cout << firstOperand << " * " << secondOperand << std::endl;
			result = firstOperand * secondOperand;
		break;

	case '/':
			std::cout << firstOperand << " / " << secondOperand << std::endl;
			if (secondOperand == 0)
				throw std::exception();
			result = firstOperand / secondOperand;
		break;
	
	default:
		throw std::exception();
		break;
	}

	_stack.push(result);
}

void RPN::calculator(const std::string &str)
{
	int i = 0;

	while (str[i])
	{
		while (std::isspace(str[i]))
			i++;		
		if (std::isdigit(str[i]))
		{
			_stack.push(strtod((str.substr(i)).c_str(), NULL));
			if (_stack.top() > 9)
				throw std::exception();
		}
		else
			selectOperation(str[i]);
		i++;
	}
	if (_stack.size() != 1)
		throw std::exception();
	std::cout << _stack.top() << std::endl;
}