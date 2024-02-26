# include "Zombie.hpp"

int main()
{
	Zombie *zombie_1 = newZombie("Carlos");
	Zombie *zombie_2 = newZombie("Roberto");
	Zombie *zombie_3 = newZombie("Tulio");

	zombie_1->announce();
	zombie_2->announce();
	zombie_3->announce();

	randomChump("Renato");
	delete zombie_1;
	randomChump("Zeca");
	delete zombie_3;
	delete zombie_2;	
}