# include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << PURPLE << "ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name) 
{
	std::cout << PURPLE << "ScavTrap constructor called" << RESET << std::endl;
	_hp = 100;
	_ep = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap &src): ClapTrap(src)
{
	*this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (this == &src)
		return (*this);
	this->ClapTrap::operator=(src);
		return (*this);
}
