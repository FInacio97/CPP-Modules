# include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << GREEN << "Its a Cat!" << RESET << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << GREEN << "Its another Cat!" << RESET << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	if (this != &src)
		this->Animal::operator=(src);
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << GREEN << "Cat died" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << CYAN << type << ": Miaauuu" << RESET << std::endl;
}