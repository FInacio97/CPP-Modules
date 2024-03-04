# include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << GREEN << "Its a weird Cat!" << RESET << std::endl;
	this->type = "Weird Cat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << GREEN << "Its another weird Cat!" << RESET << std::endl;
	this->type = "weird Cat";
	*this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
		this->WrongAnimal::operator=(src);
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << GREEN << "Weird Cat died" << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << CYAN << type << ": Bonk" << RESET << std::endl;
}