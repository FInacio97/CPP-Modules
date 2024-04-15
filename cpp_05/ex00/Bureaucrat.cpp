# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Nameless"), _grade(100){}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name)
{
    *this = src;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name),
                                                                 _grade(grade)
{
    // protect for invalid grade
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
    if (_grade > 1)
        _grade--;
    return (*this);
}

Bureaucrat &Bureaucrat::operator--()
{
    if (_grade < 150)
        _grade++;
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const src)
{
    o << GREEN << src.getName() << CYAN << ", bureaucrat grade "
        << src.getGrade() << ".\n" << RESET;
    return (o);
}