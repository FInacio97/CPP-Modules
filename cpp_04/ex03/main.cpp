# include "Cure.hpp"
# include "Ice.hpp"
# include "Character.hpp"
# include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(0, *bob);

	delete bob;
	delete me;
	delete src;
	return 0;
}

int main1()
{
	Character paul("paul");
	Character john("john");

	john.DisplaySlots();

	john.equip(new Ice());
	john.equip(new Cure());
	john.equip(new Ice());
	john.equip(new Cure());

	john.DisplaySlots();

	john.unequip(2);

	john.DisplaySlots();
	john.equip(new Ice());
	john.DisplaySlots();
	john.unequip(1);
	john.unequip(1);
	john.DisplaySlots();	
	john.DisplayFloor();

	john.use(3, paul);		// Empty slot, nothing happens
	john.use(1, paul);

	john.DisplaySlots();	
	john.DisplayFloor();

	for (int i = 0; i < NBR_SLOTS + 1; i++)		// should use only 2
		john.use(0, paul);
	
	for (int j = 0; j < NBR_SLOTS; j++)
		john.equip(new Ice());
	john.equip(new Cure());				// should not equip

	john.DisplaySlots();

	return (0);
}

int main2() // deep copy test
{
	Character paul("paul");
	Character john("john");

	john.DisplaySlots();
	paul.DisplaySlots();

	for (int k = 0; k < NBR_SLOTS; k++)
		john.equip(new Cure());

	john.DisplaySlots();
	paul.DisplaySlots();

	paul = john;

	john.DisplaySlots();
	paul.DisplaySlots();

	for (int i = 0; i < NBR_SLOTS; i++)
		paul.unequip(0);

	john.DisplaySlots();
	paul.DisplaySlots();
	
	for (int j = 0; j < NBR_SLOTS; j++)
		paul.equip(new Ice());
	
	john.DisplaySlots();
	paul.DisplaySlots();

	return (0);
}