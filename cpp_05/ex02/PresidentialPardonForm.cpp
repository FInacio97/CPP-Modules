# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("none", 25, 5), _target("none") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) : AForm(src){}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5),
                                                                             _target(target){}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
    if (this == &src)
        return (src);
    AForm::operator=(src);
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {

    this->checkRequirements(executor);
    std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox.\n" << RESET;
}