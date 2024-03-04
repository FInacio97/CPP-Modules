# include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << GREEN << "Its a Cat!" << RESET << std::endl;
	this->type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src), _brain(NULL)
{
	std::cout << GREEN << "Its another Cat!" << RESET << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	if (this == &src)
		return (*this);
	this->Animal::operator=(src);
	if (this->_brain)
		delete _brain;
	this->_brain = new Brain(*src._brain);
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << GREEN << "Cat died" << RESET << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << GREEN << type << ": Miaauuu" << RESET << std::endl;
}

Brain	*Cat::getBrain()const
{
	return (_brain);
}