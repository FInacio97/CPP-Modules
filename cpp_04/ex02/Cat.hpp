# include "AAnimal.hpp"
# include "Brain.hpp"

# ifndef CAT_HPP
# define CAT_HPP

class Cat : public AAnimal
{
	public:

		Cat(void);
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		virtual ~Cat(void);

		virtual void makeSound() const;
		virtual Brain *getBrain() const;

	private:

		Brain *_brain;
};

# endif