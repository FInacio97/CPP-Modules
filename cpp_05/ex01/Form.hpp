# include <string>

# ifndef FORM_HPP
# define FORM_HPP

class Form
{
    public:

        Form(const Form &src);
        Form(const std::string name, const int gts, const int gte);
        Form &operator=(const Form &src);
        ~Form();

        // Getters
        const std::string   &getName();
        bool                getSignature();
        const int           getGradeToSign();
        const int           getGradeToExec();

        class GradeTooHighException : public std::exception{
            virtual const char *what() throw(){
                return ("Grade too high...");
            }
        };

        class GradeTooLowException : public std::exception{
            virtual const char *what() throw(){
                return ("Grade too low...");
            }
        };

    private:
        
        Form(void);

        const std::string   _name;
        bool                _signature;
        const int           _gradeToSign;
        const int           _gradeToExec;
};

# endif