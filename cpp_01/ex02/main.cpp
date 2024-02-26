# include <string>
# include <iostream>

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

int main()
{
	const std::string str = "HI THIS IS BRAIN";
	const std::string *stringPTR = &str;
	const std::string &stringREF = str;

	std::cout << CYAN << "Memory address of str:              " << GREEN << &str << RESET << std::endl;
	std::cout << CYAN << "Memory address of str by stringPTR: " << GREEN << stringPTR << RESET << std::endl;
	std::cout << CYAN << "Memory address of str by strinREF:  " << GREEN << &stringREF << RESET << std::endl << std::endl;

	std::cout << YELLOW << "Value of str:                       " << GREEN << str << RESET << std::endl;
	std::cout << YELLOW << "Value of str by stringPTR:          " << GREEN << *stringPTR << RESET << std::endl;
	std::cout << YELLOW << "Value of str by strinREF:           " << GREEN << stringREF << RESET << std::endl;
}