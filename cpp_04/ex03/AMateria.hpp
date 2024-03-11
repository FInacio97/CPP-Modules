# include <string>
# include <iostream>
# include "ICharacter.hpp"

# ifndef AMateria_HPP
# define AMateria_HPP

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

class AMateria
{
	public:

		AMateria(void);
		AMateria(const AMateria &src);
		AMateria &operator=(const AMateria &src);
		virtual ~AMateria(void);
		AMateria(std::string const & type);

		std::string const	&getType() const; //Returns the materia type
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter& target);

	protected:

		std::string _type;
};

# endif