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
        ~ShrubberyCreationForm();
    
        void execute(Bureaucrat const & executor) const;
    
    private:

        ShrubberyCreationForm(void);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &src); ; // TODO: take care of all the = overloads, don't make them private
        
        std::string _target;
};

# endif