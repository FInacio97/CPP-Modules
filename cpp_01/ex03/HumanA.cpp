#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):name(name), weapon(weapon)
{
	
	std::cout << CYAN << name << GREEN << " entered the arena" << RESET << std::endl;
}

void HumanA::attack()
{
	std::cout << CYAN << this->name << GREEN << " attacks with their "
		<< YELLOW << this->weapon.getType() << RESET << std::endl;
}