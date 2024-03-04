#include "ClapTrap.hpp"

# ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

class FragTrap : public ClapTrap
{
	public:

		FragTrap(void);
		FragTrap(const FragTrap &src);
		FragTrap(const std::string name);
		FragTrap &operator=(const FragTrap &src);
		~FragTrap(void);

		void highFivesGuys(void);
		void attack(const std::string& target);
};

# endif