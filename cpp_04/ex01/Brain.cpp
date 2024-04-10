# include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << CYAN << "It has a brain!" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "Empty thought"; 
}

Brain::Brain(const Brain &src)
{
	std::cout << CYAN << "It has a brain! It comes from another brain..." << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &src)
{
	if (this == &src)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << CYAN << "Bye bye brain!" << RESET << std::endl;
}

std::string Brain::getIdea(int i) const
{
	return (_ideas[i]);
}

void Brain::setIdeas(const unsigned int index, const std::string &idea)
{
	if (index >= 100)
		std::cout << CYAN << "Index too high!" << std::endl;
	else
		_ideas[index] = idea;

}