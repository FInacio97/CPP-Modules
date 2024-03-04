# include "AMateria.hpp"

# ifndef	ICE_HPP
# define	ICE_HPP

class Ice : public AMateria
{
	public:

		Ice(void);
		Ice(const Ice &src);
		Ice &operator=(const Ice &src);
		virtual ~Ice(void);

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter& target);
};

# endif