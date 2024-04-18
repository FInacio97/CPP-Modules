# ifndef INTERN_CPP
# define INTERN_CPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define NBR_FORMS 3

class Intern
{
	public:

		Intern(void);
		~Intern(void);

		AForm *makeForm(std::string formName, std::string target);

		class NoFormException : public std::exception {
            public:
                virtual const char *what() const throw()
                {
                    return ("No. That form is executed elsewhere...");
                }
        };

	private:

		Intern(Intern &src);
		Intern &operator=(Intern &src);

		std::string _form_names[NBR_FORMS];
};

# endif