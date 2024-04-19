# include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong number of arguments\n";
        return 1;
    }

    std::string toConvert = av[1];
    ScalarConverter::converter(toConvert);
}