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
	_ep_clone = _ep;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
	std::cout << PURPLE << "ScavTrap copy constructor called" << RESET << std::endl;
	*this = src;
	_ep_clone = _ep;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (this == &src)
		return (*this);
	this->ClapTrap::operator=(src);
		return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << PURPLE << "ScavTrap destructor called" << RESET << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_hp <= 0)
		return ;
	std::cout << GREEN << this->_name << " is in Gate keeper mode." << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hp <= 0)
		return ;
	if (_ep == 0)
	{
		std::cout << PURPLE << _name << "doesnt have enough energy points to attack " << target << RESET << std::endl;
		return ;
	}
	std::cout << CYAN <<  "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage
		<< " points of damage!" << RESET << std::endl;
	_ep--;
}