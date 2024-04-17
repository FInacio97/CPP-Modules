
# ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

class Bureaucrat;

class Form
{
    public:

        Form(const Form &src);
        Form(const std::string name, const int gts, const int gte);
        ~Form();

        // Getters
        const std::string       &getName() const;
        bool                    getSignature() const;
        int                     getGradeToSign() const;
        int                     getGradeToExec() const;

        void beSigned(Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception{
            virtual const char *what() const throw(){
                return ("Grade too high...");
            }
        };

        class GradeTooLowException : public std::exception{
            virtual const char *what() const throw(){
                return ("Grade too low...");
            }
        };

        class FormPrevSignedException : public std::exception{
            virtual const char *what() const throw(){
                return ("Form was already signed");
            }
        };

    private:
        
        Form(void);
        Form &operator=(const Form &src);

        const std::string   _name;
        bool                _signature;
        const int           _gradeToSign;
        const int           _gradeToExec;
};

std::ostream &operator<<(std::ostream &o, Form &src);

# endif