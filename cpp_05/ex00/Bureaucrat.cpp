# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Nameless"), _grade(100){}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name)
{
    *this = src;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this == &src)
        return (*this);
    this->_grade = src._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

const std::string &Bureaucrat::getName() const
{
    return(_name);
}

int Bureaucrat::getGrade() const
{
    return(_grade);
}

Bureaucrat &Bureaucrat::operator++()
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
    return (*this);
}

Bureaucrat &Bureaucrat::operator--()
{
    // TODO: we could increment even if the grade was to low, u need to check berore incrementation
    if (_grade + 1 > 150) 
        throw Bureaucrat::GradeTooLowException();
    _grade++;
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const src)
{
    o << GREEN << src.getName() << CYAN << ", bureaucrat grade "
        << src.getGrade() << ".\n" << RESET;
    return (o);
}