# include "AMateria.hpp"

# ifndef	CURE_HPP
# define	CURE_HPP

class Cure : public AMateria
{
	public:

		Cure(void);
		Cure(const Cure &src);
		Cure &operator=(const Cure &src);
		virtual ~Cure(void);

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter& target);
};

# endif