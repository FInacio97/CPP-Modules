# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << PURPLE << "DiamontTrap default constructor called on memory address: " << GREEN << this << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << PURPLE << "DiamondTrap copy constructor called on memory address: " << GREEN << this << RESET << std::endl;
	*this = src;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << PURPLE << "DiamondTrap constructor called on memory address: " << GREEN << this << RESET << std::endl;
	this->_ep = _ep_clone;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap assignment operator" << std::endl;
	if (this == &src)
		return (*this);
	ScavTrap::operator=(src);
	FragTrap::operator=(src);
	this->_ep = _ep_clone;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << PURPLE << "Diamond destructor called" << RESET << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << CYAN << "Im " << _name << " son of " << ClapTrap::_name << std::endl;
}
