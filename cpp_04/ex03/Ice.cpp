# include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << YELLOW << "Ice default constructor called" << RESET << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	std::cout << YELLOW << "Ice copy constructor called" << RESET << std::endl;
	*this = src;
}

Ice &Ice::operator=(const Ice &src)
{
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << YELLOW << "Ice destructor called" << RESET << std::endl;
}

AMateria	*Ice::clone() const
{
	AMateria *clone = new Ice();
	return (clone);
}

void Ice::use(ICharacter& target)
{
	std::cout << CYAN << "* shoots an ice bolt at " << target.getName()  << " *" << RESET << std::endl;
}
