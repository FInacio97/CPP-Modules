# include "Intern.hpp"

Intern::Intern(void) {
    _form_names[0] = "ShrubberyCreationForm";
    _form_names[1] = "RobotomyRequestForm";
    _form_names[2] = "PresidentialPardonForm";
}

Intern::Intern(Intern &src) {
    for (int i = 0; i < NBR_FORMS; i++)
        this->_form_names[i] = src._form_names[i];
}

Intern &Intern::operator=(Intern &src) {(void) src; return(*this);}

Intern::~Intern(void) {}

AForm *createShrubberyCreationForm(const std::string &target)
{
    AForm   *form = new ShrubberyCreationForm(target);

    std::cout << GREEN << "Intern creates " << form->getName() << RESET << std::endl;
    return (form);
}

AForm *createRobotomyRequestForm(const std::string &target)
{
    AForm   *form = new RobotomyRequestForm(target);

    std::cout << GREEN << "Intern creates " << form->getName() << RESET << std::endl;
    return (form);
}

AForm *createPresidentialPardonForm(const std::string &target)
{
    AForm   *form = new PresidentialPardonForm(target);

    std::cout << GREEN << "Intern creates " << form->getName() << RESET << std::endl;
    return (form);
}

AForm *(*Intern::formConstructors[3])(const std::string &target)
                                        = { &createShrubberyCreationForm,
                                            &createRobotomyRequestForm, 
                                            &createPresidentialPardonForm };

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    int     i;

    for (i = 0; i < NBR_FORMS; i++)
    {
        if (_form_names[i] == formName)
            return (formConstructors[i](target));
    }
    
        throw Intern::NoFormException();
        return (NULL);
}

const char *Intern::NoFormException::what() const throw()
{
    return ("No. That form is executed elsewhere...");
}