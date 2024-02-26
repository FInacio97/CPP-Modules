#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_name(NULL), _hp(0), _ep(0), _attack_damage(0)
{
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string name):_name(name), _hp(10), _ep(10), _attack_damage(0)
{
	std::cout << YELLOW << "Constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &src)
{
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	this->_name = src._name;
	this->_hp = src._hp;
	this->_ep = src._ep;
	this->_attack_damage = src._attack_damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << YELLOW << "Assignment operator called" << RESET << std::endl;
	if (this == &src)
		return (*this);
	this->_name = src._name;
	this->_hp = src._hp;
	this->_ep = src._ep;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << YELLOW << "Distructor called" << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_ep == 0)
	{
		std::cout << PURPLE << _name << "doesnt have enough energy points to attack " << target << RESET << std::endl;
		return ;
	}
	std::cout << CYAN <<  "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage
		<< " points of damage!" << RESET << std::endl;
	_ep--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hp -= amount;
	if (_hp <= 0)
		std::cout << RED << _name << " Died!" << RESET << std::endl;
	else
		std::cout << CYAN << _name << " took " << amount << " damage. Hit points: "
			<< _hp << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_ep == 0)
	{
		std::cout << PURPLE << _name << "doesnt have enough energy points to restore." << RESET << std::endl;
		return ;
	}
	_hp += amount;
	_ep--;
	std::cout << CYAN << _name << " restored " << amount << " hit points. Hit points: "
			<< _hp << RESET << std::endl;
}

int ClapTrap::getHp(void)
{
	return (_hp);
}

int ClapTrap::getEp(void)
{
	return (_ep);
}

int ClapTrap::getAttackDamage(void)
{
	return (_attack_damage);
}