# include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << GREEN << "Its a Dog!" << RESET << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << GREEN << "Its another Dog!" << RESET << std::endl;
	std::cout << "yo yo yo" << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog assignment operator" <<std::endl;
	if (this == &src)
		return (*this);
	this->Animal::operator=(src);
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << GREEN << "Dog died" << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << CYAN << type << ": Woof Woof" << RESET << std::endl;
}