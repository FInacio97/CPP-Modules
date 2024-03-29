# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main()
{
	ScavTrap moedas("moedas");
	ScavTrap manel_acacio("manel_acacio");

	ScavTrap test(moedas);
	ScavTrap test2 = test;

	moedas.attack("manel_acacio");
	manel_acacio.takeDamage(moedas.getAttackDamage());
	manel_acacio.beRepaired(5);
	for (int i = 0; i <= 10; i++)
	{
		moedas.attack("manel_acacio");
		manel_acacio.takeDamage(moedas.getAttackDamage());
	}
	manel_acacio.guardGate();
	manel_acacio.attack("moedas");
	moedas.takeDamage(manel_acacio.getAttackDamage());
	manel_acacio.attack("moedas");
	moedas.takeDamage(manel_acacio.getAttackDamage());
}