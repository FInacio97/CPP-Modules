# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <cstdlib>
# include <ctime>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:

        ShrubberyCreationForm(ShrubberyCreationForm &src);
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();
    
        void execute(Bureaucrat const & executor) const;
    
    private:

        ShrubberyCreationForm(void);
        
        std::string _target;
};

# endif