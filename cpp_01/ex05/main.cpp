# include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;

	if (ac > 2)
		std::cout << RED << "Hey!! One complaint at the time" << std::endl;
	else if (ac == 1)
		std::cout << YELLOW << "C'mon, complain a little..." << std::endl;
	else
		harl.complain(av[1]);
}