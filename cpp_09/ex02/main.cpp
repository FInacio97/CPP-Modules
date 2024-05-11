# include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac == 1)
        return (1);
    PmergeMe p;

    p.parsing(ac, av);
    p.jacobsGenerator();

    p.sorting();
    // p.sortPairsVector();
    // p.sortHalfVector(0);
    // p.displayListOrVector(0);
    // p.sortWithJacobsVector(0);

    // p.displayListOrVector(0);

    

}