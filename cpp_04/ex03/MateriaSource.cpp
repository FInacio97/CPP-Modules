# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << YELLOW << "MateriaSource Constructor called" << RESET << std::endl;

	for (int i = 0; i < NBR_TEMPLATES; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << YELLOW << "MateriaSource copy Constructor called" << RESET << std::endl;
	*this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this == &src)
		return (*this);
	
	for (int i = 0; i < NBR_TEMPLATES; i++)
	{
		if (this->_templates[i])
		{
			delete this->_templates[i];
			this->_templates[i] = NULL;
		}
		if (src._templates[i])
			this->_templates[i] = src._templates[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << YELLOW << "MateriaSource destructor called" << RESET << std::endl;
	
	for (int i = 0; i < NBR_TEMPLATES; i++)
		if (_templates[i])
			delete _templates[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < NBR_TEMPLATES; i++)
		if (!_templates[i])
		{
			_templates[i] = m;
			std::cout << CYAN << "Materia " << m->getType() << " was saved"<< RESET << std::endl;
			return ;
		}
	std::cout << RED << "MateriaSorce's inventory is full" << RESET << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < NBR_TEMPLATES; i++)
	{
		if (!_templates[i])
			continue ;
		if (type == _templates[i]->getType())
			return (_templates[i]->clone());
	}
	std::cout << RED << "MateriaSource doesnt know " << type << RESET << std::endl;
	return (NULL);
}

void MateriaSource::displayInventory()
{
	std::cout << GREEN << "MateriaSource's Inventory:" << RESET << std::endl;
	
	for (int i = 0; i < NBR_TEMPLATES; i++)
	{
		if (_templates[i])
			std::cout << GREEN << _templates[i]->getType() << RESET << std::endl;
		else
			std::cout << RED << "Empty" << RESET << std::endl;
	}
}