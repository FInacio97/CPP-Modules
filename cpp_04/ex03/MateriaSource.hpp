# include "IMateriaSource.hpp"

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# define NBR_TEMPLATES 4

class MateriaSource : public IMateriaSource
{
	public:

		MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource &operator=(const MateriaSource &src);
		virtual ~MateriaSource();
		
		virtual void learnMateria(AMateria *m);
		virtual AMateria* createMateria(std::string const & type);

		void displayInventory();

	private:

		AMateria *_templates[NBR_TEMPLATES];

};

# endif