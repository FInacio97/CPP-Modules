# include <iostream>
# include <string>

# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

class WrongAnimal
{
	public:

		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal &operator=(const WrongAnimal &src);
		virtual ~WrongAnimal(void);

		std::string getType() const;
		void		makeSound() const;

	protected:

		std::string type;
};

# endif