# include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe p;

    p.parsing(ac, av);
    p.jacobsGenerator();
    p.sortPairsVector();
    p.sortHalfVector(0);
    p.displayListOrVector(0);
}