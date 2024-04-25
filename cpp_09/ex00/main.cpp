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

        a.extractDataBase();


        
        // a.parser(av[1]);
        // a.checkValue(av[1]);
        // a.checkDate(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    
}