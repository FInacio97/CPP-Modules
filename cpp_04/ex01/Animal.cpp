# include "Animal.hpp"

Animal::Animal(void): type("Not defined")
{
	std::cout << YELLOW << "An Animal is born" << RESET << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << YELLOW << "Another Animal is born" << RESET << std::endl;
	*this = src;
}

Animal &Animal::operator=(const Animal &src)
{
	if(this != &src)
		this->type = src.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << YELLOW << "Animal died" << RESET << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << type << YELLOW << ": * undefined animal sounds *" << RESET << std::endl;
}
