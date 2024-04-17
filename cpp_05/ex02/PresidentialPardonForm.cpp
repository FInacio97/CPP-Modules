# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) : AForm(AForm::src){}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5),
                                                                             _target(target){}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src){(void) src}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    std::cout 
}