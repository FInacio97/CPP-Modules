# include "RPN.hpp"

int main(int ac, char **av)
{
	RPN rpn;

	if (ac != 2)
	{
		std::cout << "Bad input\n";
		return (1);
	}


	int i = -1;

	while (av[++i])
		std::cout << av[i] << std::endl;

	try
	{
		std::string str = av[1];
		av++;
		rpn.calculator(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error\n";
	}
	
}