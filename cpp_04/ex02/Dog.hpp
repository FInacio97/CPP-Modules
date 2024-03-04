# include "AAnimal.hpp"
# include "Brain.hpp"

# ifndef DOG_HPP
# define DOG_HPP

class Dog : public AAnimal
{
	public:

		Dog(void);
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		virtual ~Dog(void);

		virtual void makeSound() const;
		virtual Brain *getBrain() const;

	private:

		Brain *_brain;
};

# endif