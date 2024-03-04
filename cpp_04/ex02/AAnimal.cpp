# include "AAnimal.hpp"

AAnimal::AAnimal(void): type("Not defined")
{
	std::cout << YELLOW << "An Animal is born" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << YELLOW << "Another Animal is born" << RESET << std::endl;
	*this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	if(this != &src)
		this->type = src.type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << YELLOW << "Animal died" << RESET << std::endl;
}

std::string AAnimal::getType() const
{
	return (type);
}
