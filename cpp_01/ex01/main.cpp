# include "Zombie.hpp"

static void horde_anouncement(int N, Zombie *horde)
{
	for (int i = 0; i < N; i++)
		horde[i].announce();
}

int main()
{
	Zombie *horde_1;
	Zombie *horde_2;
	Zombie *horde_3;
	const int N1 = 0;
	const int N2 = H2;
	const int N3 = H3;

	horde_1 = zombieHorde(N1, "Joca");
	horde_anouncement(N1, horde_1);
	horde_2 = zombieHorde(N2, "Ramiro");
	horde_3 = zombieHorde(N3, "Hugo Sugo");
	horde_anouncement(N2, horde_2);
	horde_anouncement(N3, horde_3);
	
	// if (N1)
		delete [] horde_1;
	if (N2)
		delete [] horde_2;
	if (N3)
		delete [] horde_3;
}