# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm(), _target("none") {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src) : AForm(src){}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45),
                                                                             _target(target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &src)
{
    if (this == &src)
        return (src);
    AForm::operator=(src);
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

    this->checkRequirements(executor);
    std::cout << GREEN << _target << " * Driling noises *\n" << RESET;
    std::srand(std::time(NULL));
    if (rand() % 2)
        std::cout << GREEN << _target << " was robotomized!\n" << RESET;
    else
        std::cout << RED << _target << " robotomization failed\n" << RESET;
}