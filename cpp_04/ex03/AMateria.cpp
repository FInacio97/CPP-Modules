# include "AMateria.hpp"

AMateria::AMateria(void): _type("Undefined")
{
	std::cout << YELLOW << "AMateria default constructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	std::cout << YELLOW << "AMateria copy constructor called" << RESET << std::endl;
	*this = src;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	(void) src;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << YELLOW << "AMateria destructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << YELLOW << "AMateria constructor called" << RESET << std::endl;
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << CYAN << "* Something happened to " << target.getName() << RESET << std::endl;
}