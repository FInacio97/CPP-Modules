# include "DiamondTrap.hpp"

int main()
{
	DiamondTrap rocky("rocky");

	std::cout << "HP: " << rocky.getHp() << std::endl;
	std::cout << "EP: " << rocky.getEp() << std::endl;
	std::cout << "AD: " << rocky.getAttackDamage() << std::endl;

	DiamondTrap test(rocky);
	std::cout << "HP: " << test.getHp() << std::endl;
	std::cout << "EP: " << test.getEp() << std::endl;
	std::cout << "AD: " << test.getAttackDamage() << std::endl;

	rocky.guardGate();
	rocky.highFivesGuys();
	rocky.attack("joca");
	rocky.whoAmI();
}