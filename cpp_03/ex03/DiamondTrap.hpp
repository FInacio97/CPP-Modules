# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:

		DiamondTrap(void);
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap(const std::string name);
		DiamondTrap &operator=(const DiamondTrap &src);
		~DiamondTrap(void);

		void whoAmI();

	private:

		std::string _name;

};

# endif