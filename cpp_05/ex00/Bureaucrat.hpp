# include <string>
# include <iostream>

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"


class Bureaucrat
{
    public:

        Bureaucrat(const Bureaucrat &src);
        Bureaucrat(const std::string &name, const int grade);
        Bureaucrat &operator=(const Bureaucrat &src);
        ~Bureaucrat(void);

        const std::string &getName() const;
        int         getGrade() const;

        Bureaucrat &operator++();
        Bureaucrat &operator--();

        

    private:

        Bureaucrat(void);
        const std::string   _name;
        int                 _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const src);

# endif