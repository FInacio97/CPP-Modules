#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			av[i][j] = toupper(av[i][j]);
		std::cout << av[i];
		if (i < ac -1)
			std::cout << " ";
	}
	std::cout << std::endl;
}