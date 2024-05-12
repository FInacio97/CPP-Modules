# include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac == 1)
        return (1);
    PmergeMe p;

    try
    {
        p.parsing(ac, av);
        std::cout <<  "parsing ok\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error\n";
        return (1);
    }
    
    p.jacobsGenerator();

    p.sorting();
}