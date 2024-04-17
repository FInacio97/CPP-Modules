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
    _grade--;
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    return (*this);
}

Bureaucrat &Bureaucrat::operator--()
{
    _grade++;
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const src)
{
    o << GREEN << src.getName() << CYAN << ", bureaucrat grade "
        << src.getGrade() << ".\n" << RESET;
    return (o);
}

void Bureaucrat::signAForm(AForm &aform)
{
    try
    {
        aform.beSigned(*this);
        std::cout << GREEN << _name << " signed " << aform.getName() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << RED << _name << " couldn't sign " << aform.getName()
            << " because grade is too low"  << RESET  << std::endl;
        throw ;
    }
    
}