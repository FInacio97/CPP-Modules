# include "Bureaucrat.hpp"
# include "Intern.hpp"

int main()
{
    {
        AForm *form;

    std::cout << "+++++ PresidentialPardonForm Test +++++\n\n";
        try
        {
            Intern      Miguel;
            Bureaucrat  Clara("Clara", 1);

            form = Miguel.makeForm("PresidentialPardonForm", "yooo");
            std::cout << *form;
            Clara.signForm(*form);
            std::cout << *form;
            Clara.executeForm(*form);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        delete form;
    }

    std::cout << "\n+++++ RobotomyRequestForm Test +++++\n\n";


    {
        AForm *form;

        try
        {
            Intern      Miguel;
            Bureaucrat  Clara("Clara", 1);

            form = Miguel.makeForm("RobotomyRequestForm", "yooo");
            std::cout << *form;
            Clara.signForm(*form);
            std::cout << *form;
            Clara.executeForm(*form);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        delete form;
    }

    std::cout << "\n+++++ ShrubberyCreationForm Test +++++\n\n";
    {
        AForm *form;

        try
        {
            Intern      Miguel;
            Bureaucrat  Clara("Clara", 1);

            form = Miguel.makeForm("ShrubberyCreationForm", "yooo");
            std::cout << *form;
            Clara.signForm(*form);
            std::cout << *form;
            Clara.executeForm(*form);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        delete form;
    }

    std::cout << "\n+++++ Wrong Form Test +++++\n\n";
    {
        AForm *form;

        try
        {
            Intern      Miguel;
            Bureaucrat  Clara("Clara", 1);

            form = Miguel.makeForm("AnotherForm", "yooo");
            std::cout << *form;
            Clara.signForm(*form);
            std::cout << *form;
            Clara.executeForm(*form);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            form = NULL;
        }
        if (form)
            delete form;
    }
}