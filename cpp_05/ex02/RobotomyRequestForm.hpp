# ifndef ROBOTOMYREQUEST_HPP
# define ROBOTOMYREQUEST_HPP

# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:

        RobotomyRequestForm(RobotomyRequestForm &src);
        RobotomyRequestForm(const std::string &target);
        ~RobotomyRequestForm();
    
        void execute(Bureaucrat const & executor) const;
    
    private:

        RobotomyRequestForm(void);
        RobotomyRequestForm &operator=(RobotomyRequestForm &src); ; // TODO: take care of all the = overloads, don't make them private
        
        std::string _target;
};

# endif