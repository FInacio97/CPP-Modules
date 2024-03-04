# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("Not defined")
{
	std::cout << YELLOW << "A weird Animal is born" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << YELLOW << "Another weird Animal is born" << RESET << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	if(this != &src)
		*this = src;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << YELLOW << "weird Animal died" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << CYAN << type << ": * undefined weird animal sounds *" << RESET << std::endl;
}