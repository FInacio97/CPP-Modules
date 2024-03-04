# include "Character.hpp"

Character::Character(void) : _name ("nameless")
{
	std::cout << YELLOW << "Character default constructor called" << RESET << std::endl;
	
	for (int i = 0; i < NBR_SLOTS; i++)
		_slots[i] = NULL;
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
		*this->_slots[i] = *src._slots[i];
	return (*this);
}

Character::~Character()
{
	std::cout << YELLOW << "Character destructor called" << RESET << std::endl;
}

Character::Character(const std::string &name) : _name(name)
{
	std::cout << YELLOW << "Character constructor called" << RESET << std::endl;
	
	for (int i = 0; i < NBR_SLOTS; i++)
		_slots[i] = NULL;
}

std::string const &Character::getName() const
{
	return(_name);
}

void Character::equip(AMateria* m)
{

	for (int i = 0; i < NBR_SLOTS; i++)
	{
		if (!_slots[i])
		{
			_slots[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	for (int i = idx; i < NBR_SLOTS; i++)
	{
		if (i == NBR_SLOTS - 1)
			_slots[i] = NULL;
		if (!_slots[i])
			break;
		_slots[i] = _slots[i + 1];
	}
}


void Character::DisplaySlots() const
{
	std::cout << GREEN << _name << " slots:" << RESET << std::endl;
	for (int i = 0; i < NBR_SLOTS; i++)
		std::cout << GREEN << "\t" << _slots[i]->getType() << RESET << std::endl;
}