# include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << YELLOW << "Cure default constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure &src)
{
	std::cout << YELLOW << "Cure copy constructor called" << RESET << std::endl;
	*this = src;
}

Cure &Cure::operator=(const Cure &src)
{
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << YELLOW << "Cure destructor called" << RESET << std::endl;
}

AMateria	*Cure::clone() const
{
	AMateria *clone = new Cure();
	return (clone);
}

void Cure::use(ICharacter& target)
{
	std::cout << CYAN << "* heals " << target.getName()  << " ’s wounds *" << RESET << std::endl;
}
