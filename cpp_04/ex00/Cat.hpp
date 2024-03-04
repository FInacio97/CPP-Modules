# include "Animal.hpp"

# ifndef CAT_HPP
# define CAT_HPP

class Cat : public Animal
{
	public:

		Cat(void);
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		virtual ~Cat(void);

		virtual void makeSound() const;
};

# endif