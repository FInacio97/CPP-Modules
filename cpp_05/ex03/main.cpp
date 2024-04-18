# include "Bureaucrat.hpp"
# include "Intern.hpp"

int main()
{
    {
        AForm *form;

        try
        {
            Intern      Miguel;
            Bureaucrat  Clara("Clara", 150);

            form = Miguel.makeForm("PresidentialPardonForm", "yooo");
            std::cout << *form;
            Clara.signAForm(*form);
            std::cout << *form;
            Clara.executeForm(*form);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        delete form;
    }
}