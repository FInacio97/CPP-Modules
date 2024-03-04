# include <iostream>
# include <string>
# include "Brain.hpp"

# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

class Animal
{
	public:

		Animal(void);
		Animal(const Animal &src);
		Animal &operator=(const Animal &src);
		virtual ~Animal(void);

		std::string 	getType() const;
		virtual void 	makeSound() const;

	protected:

		std::string	type;
};

# endif