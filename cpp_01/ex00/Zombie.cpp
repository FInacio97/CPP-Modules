
#include "Zombie.hpp"

Zombie::Zombie(std::string name):name(name)
{
	std::cout << CYAN << this->name << ":" << RED << " has turn into a zombie" << RESET
		 << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << CYAN << this->name << ":" << GREEN << " has died" << RESET
		 << std::endl;
}

void Zombie::announce(void)
{
	std::cout << CYAN << this->name << ":" << YELLOW << " BraiiiiiiinnnzzzZ..." << RESET
		 << std::endl;
}