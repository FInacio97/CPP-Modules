# include <string>
# include <iostream>

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

class AForm;

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

        class GradeTooHighException : public std::exception { 
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade to high..."); //TODO: again, this can't be here. u should change it in all the files
                }
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade to low...");
                }
        };

        void signAForm(AForm &aform); //TODO: the name should be signForm
       void executeForm(AForm const & form) const;

    private:

        Bureaucrat(void);
        const std::string   _name;
        int                 _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const src);

# endif