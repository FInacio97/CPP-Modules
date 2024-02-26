#include "HumanB.hpp"

HumanB::HumanB(std::string name):name(name)
{
	this->weapon = NULL;
	std::cout << CYAN << name << GREEN << " entered the arena" << RESET << std::endl;
}

void HumanB::attack()
{
	if (!this->weapon)
	{
		std::cout << CYAN << this->name << GREEN << " attacks with their "
			<< YELLOW << "hands" << RESET << std::endl;
		return ;
	}
	std::cout << CYAN << this->name << GREEN << " attacks with their "
		<< YELLOW << this->weapon->getType() << RESET << std::endl;
}

void HumanB::set_weapon(Weapon &weapon)
{
	this->weapon = &weapon;
	std::cout << CYAN << name << GREEN << " has picked up a " << YELLOW
		<< this->weapon->getType() << RESET << std::endl;
}
