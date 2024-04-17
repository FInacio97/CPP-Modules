# ifndef INTERN_CPP
# define INTERN_CPP

class Intern
{
	public:

		Intern(void);
		~Intern(void);

		AForm *makeForm(std::string formName, std::string target);

	private:

		Intern(Intern &src);
		Intern &operator=(Intern &src);
};

# endif