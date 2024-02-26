# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;

	// if (N <= 0)
	// {
	// 	std::cout << RED << "NUMBER OF ZOMBIES HAS TO BE GREATER THAN ZERO" << RESET << std::endl;
	// 	return (NULL);
	// }
	std::cout << CYAN << "     * CRATING horde *" << RESET << std::endl;
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].set_zombie_name(name);
	std::cout << CYAN << "     * horde CREATED *" << RESET << std::endl << std::endl;
	return (horde);
}