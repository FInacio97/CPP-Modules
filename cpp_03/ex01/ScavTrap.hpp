# include "ClapTrap.hpp"

# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(ClapTrap &src);
		ScavTrap &operator=(const ScavTrap &src);
		~ScavTrap(void);

		void guardGate();
};

# endif