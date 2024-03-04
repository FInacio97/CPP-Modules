# include "Animal.hpp"

# ifndef DOG_HPP
# define DOG_HPP

class Dog : public Animal
{
	public:

		Dog(void);
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		virtual ~Dog(void);

		virtual void makeSound() const;
};

# endif