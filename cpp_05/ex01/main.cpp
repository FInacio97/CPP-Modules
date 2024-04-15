# include "Bureaucrat.hpp"

int main()
{
    Bureaucrat Fernando("Fernando", 75);
    Bureaucrat Carlos("Carlos", 5);

    std::cout << Fernando << Carlos;

    Bureaucrat copy(Fernando);

    std::cout << copy;

    copy = Carlos;

    std::cout << copy;

    ++Carlos;
    --Fernando;

    std::cout << Fernando << Carlos;
}