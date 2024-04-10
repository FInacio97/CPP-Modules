
# include <iostream>
# include <string>

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

class Zombie
{
	public:

		Zombie(void);
		~Zombie(void);

		void announce( void );
		void set_zombie_name(std::string name);

	private:

		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

# endif