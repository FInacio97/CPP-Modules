# include "Bureaucrat.hpp"

int main()
{
    std::cout << YELLOW << "+++++ TEST ONE: All good +++++\n" << RESET;
    {
        try
        {
            Bureaucrat Fernando("Fernando", 75);
            Bureaucrat Carlos("Carlos", 33);

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
    
    std::cout << YELLOW << "\n+++++ TEST TWO: Grade too high +++++\n" << RESET;

    {
        try
        {
            Bureaucrat wrong("Wrong", 0);
            std::cout << RED << "If this prints, im an idiot..." << RESET << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }

    std::cout << YELLOW << "\n+++++ TEST THREE: Grade too Low +++++\n" << RESET;

    {
        try
        {
            Bureaucrat wrong("Wrong", 200);
            std::cout << RED << "If this prints, im an idiot..." << RESET << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }

    std::cout << YELLOW << "\n+++++ TEST FOUR: Invalid increment +++++\n" << RESET;

    {
        try
        {
            Bureaucrat wrong("Wrong", 1);
            std::cout << wrong;
            ++wrong;
            std::cout << RED << "If this prints, im an idiot..." << RESET << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}