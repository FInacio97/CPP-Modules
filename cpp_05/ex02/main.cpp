# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << YELLOW << "TEST ONE: All goes right\n" << RESET;
    {
        try
        {
            PresidentialPardonForm aaaa("aaaaa");
            Bureaucrat carla("Carla", 1);

            std::cout << aaaa;
            carla.signForm(aaaa);
            std::cout << aaaa;
            carla.executeForm(aaaa);
        }
        catch(const std::exception& e)
        {
        }
    }

    std::cout << YELLOW << "TEST TWO: Form signed, but not executed\n" << RESET;
    {
        try
        {
            PresidentialPardonForm aaaa("aaaaa");
            Bureaucrat carla("Carla", 20);

            std::cout << aaaa;
            carla.signForm(aaaa);
            std::cout << aaaa;
            carla.executeForm(aaaa);
        }
        catch(const std::exception& e)
        {
        }
    }

    std::cout << YELLOW << "TEST THREE: try to execut an unsigned form\n" << RESET;
    {
        try
        {
            PresidentialPardonForm aaaa("aaaaa");
            Bureaucrat carla("Carla", 1);

            std::cout << aaaa;
            carla.executeForm(aaaa);
        }
        catch(const std::exception& e)
        {
        }
    }

    std::cout << YELLOW << "TEST FOUR: All goes right (Robotomy)\n" << RESET;
    {
        try
        {
            RobotomyRequestForm aaaa("aaaaa");
            Bureaucrat carla("Carla", 1);

            std::cout << aaaa;
            carla.signForm(aaaa);
            std::cout << aaaa;
            carla.executeForm(aaaa);
        }
        catch(const std::exception& e)
        {
        }
    }

    std::cout << YELLOW << "TEST FOUR: All goes right (Shrubbery)\n" << RESET;
    {
        try
        {
            PresidentialPardonForm aaaa("aaaaa");
            Bureaucrat carla("Carla", 5);

            std::cout << aaaa;
            carla.signForm(aaaa);
            std::cout << aaaa;
            carla.executeForm(aaaa);
        }
        catch(const std::exception& e)
        {
        }
    }
}