# include <iostream>
# include <string>

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &src);
		~ClapTrap(void);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		int getHp(void);
		int getEp(void);
		int getAttackDamage(void);

	protected:

		std::string			_name;
		int					_hp;
		int					_ep;
		int					_attack_damage;
};

# endif