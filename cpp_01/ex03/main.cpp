#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
{
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
club.setType("some other type of club");
bob.attack();
}
{
Weapon club = Weapon("crude spiked club");
HumanB jim("Jim");
jim.set_weapon(club);
jim.attack();
club.setType("some other type of club");
jim.attack();
}

}
int main()
{
	Weapon weapon("hammer");

	HumanA bruno("Bruno", weapon);
	bruno.attack();
	weapon.setType("bow and arrow");
	bruno.attack();
	HumanB aires("Aires");
	aires.set_weapon(weapon);
	aires.attack();
	weapon.setType("spoon");
	aires.attack();
}