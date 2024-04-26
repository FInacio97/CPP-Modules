# include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void) av;
    if (ac != 2)
    {
        std::cout << "wrong number of arguments\n";
        return (0);
    }
    try
    {
        BitcoinExchange a;

        a.extractDB();
        // a.displayMap();
        a.Exchange(av[1]);

    }
    catch(const std::exception& e)
    {
        std::cout << e.what();
    }
    
}