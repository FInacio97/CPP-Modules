# include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Fernando("Fernando", 75);
        Bureaucrat Carlos("Carlos", 533);

        std::cout << Fernando << Carlos;

        Bureaucrat copy(Fernando);

        std::cout << copy;

        copy = Carlos;

        std::cout << copy;

        ++Carlos;
        --Fernando;

        std::cout << Fernando << Carlos;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}