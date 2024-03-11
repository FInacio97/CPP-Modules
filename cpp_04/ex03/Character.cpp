# include "Character.hpp"

Character::Character(void) : _name ("nameless")
{
	std::cout << YELLOW << "Character default constructor called" << RESET << std::endl;
	
	for (int i = 0; i < NBR_SLOTS; i++)
	{
		_slots[i] = NULL;
		_floor[i] = NULL;
	}
}

Character::Character(const Character &src)
{
	*this = src;
}

Character &Character::operator=(const Character &src)
{
	if (this == &src)
		return (*this);
	this->_name = src._name;
	
	for (int i = 0; i < NBR_SLOTS; i++)
	{
		if (this->_slots[i])
		{
			delete this->_slots[i];
			this->_slots[i] = NULL;
		}
		if (src._slots[i])
			this->_slots[i] = src._slots[i]->clone();


		if (this->_floor[i])
		{
			delete this->_floor[i];
			this->_floor[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << YELLOW << _name << RESET << " goes away" << std::endl;
	for (int i = 0; i < NBR_SLOTS; i++)
	{
		if (_slots[i])
			delete _slots[i];
		if (_floor[i])
		{
			std::cout << "antes" << std::endl;
			delete _floor[i];
			std::cout << "depois" << std::endl;
		}
	}
}

Character::Character(const std::string &name) : _name(name)
{
	std::cout << YELLOW << name << RESET << " arrives in the scene" << std::endl;
	
	for (int i = 0; i < NBR_SLOTS; i++)
	{
		_slots[i] = NULL;
		_floor[i] = NULL;
	}
}

std::string const &Character::getName() const
{
	return(_name);
}

void Character::equip(AMateria* m)
{

	for (int i = 0; i < NBR_SLOTS; i++)
	{
		if (!this->_slots[i])
		{
			this->_slots[i] = m;
			break ;
		}
		if (i == NBR_SLOTS - 1)
		{
			std::cout << RED << "Inventory full. " << m->getType() << " will be deleted." << std::endl;
			delete m;
		}
	}

	for (int j = 0; j < NBR_SLOTS; j++)
	{
		if (this->_floor[j])
		{
			delete this->_floor[j];
			this->_floor[j] = NULL;
		}
	}
}

void Character::unequip(int idx)
{
	AMateria *temp = _slots[idx];

	for (int i = idx; i < NBR_SLOTS; i++)
	{
		if (i == NBR_SLOTS - 1)
			_slots[i] = NULL;
		if (!_slots[i])
			break;
		_slots[i] = _slots[i + 1];
	}

	for (int j = 0; j < NBR_SLOTS; j++)
	{
		if (!_floor[j])
		{
			_floor[j] = temp;
			break ;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= NBR_SLOTS || idx < 0 || !this->_slots[idx])
		return ;

	AMateria *temp = this->_slots[idx];

	this->_slots[idx]->use(target);

	for (int i = idx; i < NBR_SLOTS; i++)
	{
		if (i == NBR_SLOTS - 1)
			_slots[i] = NULL;
		if (!_slots[i])
			break;
		_slots[i] = _slots[i + 1];
	}

	delete temp;
}

void Character::DisplaySlots() const
{
	std::cout << GREEN << _name << " slots:" << RESET << std::endl;
	for (int i = 0; i < NBR_SLOTS; i++)
	{
		if (!_slots[i])
		{
			std::cout << RED << "\tEmpty" << RESET << std::endl;
			continue ;
		}
		std::cout << GREEN << "\t" << _slots[i]->getType() << RESET << std::endl;
	}
}

void Character::DisplayFloor() const
{
	std::cout << GREEN << _name << " floor:" << RESET << std::endl;
	for (int i = 0; i < NBR_SLOTS; i++)
	{
		if (!_floor[i])
		{
			std::cout << RED << "\tEmpty" << RESET << std::endl;
			continue ;
		}
		std::cout << GREEN << "\t" << _floor[i]->getType() << RESET << std::endl;
	}
}