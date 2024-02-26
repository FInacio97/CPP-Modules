# include <string>
# include <iostream>

# ifndef WEAPON_HPP
# define WEAPON_HPP

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

class Weapon
{
	public:

		Weapon(std::string weapon);
		~Weapon();

		std::string	getType(void);
		void		setType(std::string name);

	private:

		std::string type;
};

# endif