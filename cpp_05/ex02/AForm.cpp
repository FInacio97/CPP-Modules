# include "AForm.hpp"

AForm::AForm(void) : _name("Nameless"), _signature(false),
                    _gradeToSign(0), _gradeToExec(0) {}

AForm::AForm(const AForm &src) : _name(src._name), _signature(false),
                             _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {}

AForm::AForm(const std::string name, const int gts, const int gte) : _name(name), _signature(false),
                           _gradeToSign(gts), _gradeToExec(gte)
{
    if (_gradeToSign > 150 || _gradeToExec > 150)
        throw AForm::GradeTooLowException();
    if (_gradeToSign < 1 || _gradeToExec < 1)
        throw AForm::GradeTooHighException();
}

AForm    &AForm::operator=(const AForm &src) {
    if (this == &src)
        return (*this);
    this->_signature = src._signature;
    return (*this);
}

AForm::~AForm() {}

std::ostream &operator<<(std::ostream &o, AForm &src)
{
    o << CYAN << "+++++++++++++++++++++++++++++++++++++++++++++++++++\n" << RESET;
    o << PURPLE << "\t" << src.getName() << CYAN << " AForm Info:\n" << RESET;
    o << YELLOW << "\t\tGrade to sign--------> " << CYAN << src.getGradeToSign() << std::endl << RESET;
    o << YELLOW << "\t\tGrade to execute-----> " << CYAN << src.getGradeToExec() << std::endl << RESET;

    if (src.getSignature())
        o << YELLOW << "\tStatus---------------> " << GREEN << "Signed." << std::endl << RESET;
    else
        o << YELLOW << "\tStatus---------------> " << RED << "Not Signed." << std::endl << RESET;

    o << CYAN << "+++++++++++++++++++++++++++++++++++++++++++++++++++\n" << RESET;
    return (o);
}

const std::string &AForm::getName() const {
    return (_name);
}

bool AForm::getSignature() const {
    return (_signature);
}

int AForm::getGradeToSign() const {
    return (_gradeToSign);
}

int AForm::getGradeToExec() const {
    return (_gradeToExec);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (_signature)
        throw AForm::FormPrevSignedException();
    if (bureaucrat.getGrade() <= _gradeToSign)
         _signature = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::checkRequirements(const Bureaucrat &executor) const
{
    if (!_signature)
        throw AForm::FormUnsignedException();
    if (executor.getGrade() > _gradeToExec)
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high...");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low...");
}

const char *AForm::FormPrevSignedException::what() const throw()
{
    return ("Form was already signed");
}

const char *AForm::FormUnsignedException::what() const throw()
{
    return ("Form needs to be signed!");
}