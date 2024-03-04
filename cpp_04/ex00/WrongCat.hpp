# include "WrongAnimal.hpp"

# ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

class WrongCat : public WrongAnimal
{
	public:

		WrongCat(void);
		WrongCat(const WrongCat &src);
		WrongCat &operator=(const WrongCat &src);
		~WrongCat(void);

		void makeSound() const;
};

# endif