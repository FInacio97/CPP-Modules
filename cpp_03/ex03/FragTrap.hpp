#include "ClapTrap.hpp"

# ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

class FragTrap : virtual public ClapTrap
{
	public:

		FragTrap(void);
		FragTrap(const FragTrap &src);
		FragTrap(const std::string name);
		FragTrap &operator=(const FragTrap &src);
		~FragTrap(void);

		void highFivesGuys(void);
};

# endif