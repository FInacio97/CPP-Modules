# include <string>
# include <iostream>
#include "Weapon.hpp"

# ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB
{
	public:

		HumanB(std::string name);
		
		void attack();
		void set_weapon(Weapon &weapon);

	private:

		std::string name;
		Weapon		*weapon;
};

# endif