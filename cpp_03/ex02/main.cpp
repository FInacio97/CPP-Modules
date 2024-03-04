# include "ClapTrap.hpp"
# include "FragTrap.hpp"

int main()
{
	FragTrap moedas("moedas");
	FragTrap manel_acacio("manel_acacio");

	moedas.attack("manel_acacio");
	manel_acacio.takeDamage(moedas.getAttackDamage());
	manel_acacio.beRepaired(5);
	for (int i = 0; i <= 10; i++)
	{
		moedas.attack("manel_acacio");
		manel_acacio.takeDamage(moedas.getAttackDamage());
		if (manel_acacio.getHp() <= 0)
			return (0);
	}
	manel_acacio.highFivesGuys();
	manel_acacio.attack("moedas");
	moedas.takeDamage(manel_acacio.getAttackDamage());
	manel_acacio.attack("moedas");
	moedas.takeDamage(manel_acacio.getAttackDamage());
}