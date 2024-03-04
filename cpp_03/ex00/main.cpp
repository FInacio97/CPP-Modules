# include "ClapTrap.hpp"

int main()
{
	ClapTrap moedas("moedas");
	ClapTrap manel_acacio("manel_acacio");

	ClapTrap test(moedas);

	moedas.attack("manel_acacio");
	manel_acacio.takeDamage(moedas.getAttackDamage());
	manel_acacio.beRepaired(5);
	for (int i = 0; i <= 10; i++)
	{
		moedas.attack("manel_acacio");
		manel_acacio.takeDamage(moedas.getAttackDamage());
	}
	manel_acacio.attack("moedas");
	moedas.takeDamage(8);
	manel_acacio.attack("moedas");
	moedas.takeDamage(3);
}