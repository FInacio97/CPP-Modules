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
        RobotomyRequestForm &operator=(RobotomyRequestForm &src);
        
        std::string _target;
};

# endif