# ifndef INTERN_CPP
# define INTERN_CPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define NBR_FORMS 3
class Intern;


class Intern
{
	public:

		Intern(void);
		~Intern(void);

		AForm *makeForm(const std::string &formName, const std::string &target);
		
		class NoFormException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

	private:

		Intern(Intern &src);
		Intern &operator=(Intern &src);

		static AForm *(*formConstructors[3])(const std::string &target);
		std::string _form_names[NBR_FORMS];
};

# endif