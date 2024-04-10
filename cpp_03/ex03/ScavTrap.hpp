# include "ClapTrap.hpp"

# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : virtual public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &src);
		ScavTrap &operator=(const ScavTrap &src);
		~ScavTrap(void);

		void guardGate();
		void attack(const std::string& target); 
	
	protected:

		int _ep_clone;
};

# endif