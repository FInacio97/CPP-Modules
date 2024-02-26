
#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "No name";
	std::cout << RED << "Someone was turned into a zombie..." << RESET
		 << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << CYAN << this->name << GREEN << ": has died" << RESET
		 << std::endl;
}

void Zombie::announce(void)
{
	std::cout << CYAN << this->name << CYAN << ": BraiiiiiiinnnzzzZ..." << RESET
		 << std::endl;
}

void Zombie::set_zombie_name(std::string name)
{
	if (name[0] == 0)
		return ;
	this->name = name;
	std::cout << CYAN << this->name << PURPLE << ": Im a zombie" << RESET
		 << std::endl;
}