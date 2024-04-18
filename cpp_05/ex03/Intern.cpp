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

AForm *Intern::makeForm(std::string formName, std::string target)
{
    AForm   *form;
    int     i;

    for (i = 0; i < NBR_FORMS; i++)
        if (_form_names[i] == formName)
            break;
    switch (i)
    {
    case 0:
        form = new ShrubberyCreationForm(target);
        break;
    
    case 1:
        form = new RobotomyRequestForm(target);
        break;
    
    case 2:
        form = new PresidentialPardonForm(target);
        break;

    default:
        throw Intern::NoFormException();
        break;
    }
    
    std::cout << GREEN << "Intern creates " << form->getName() << RESET << std::endl;
    return (form);
}