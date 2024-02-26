# include "Weapon.hpp"

Weapon::Weapon(std::string weapon):type(weapon)
{

}

Weapon::~Weapon()
{
	
}

std::string	Weapon::getType(void)
{
	return (this->type);
}

void		Weapon::setType(std::string name)
{
	this->type = name;
}