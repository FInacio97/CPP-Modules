# ifndef PRESITENTIALPARDONFORM_HPP
# define PRESITENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:

        PresidentialPardonForm(PresidentialPardonForm &src);
        PresidentialPardonForm(const std::string &target);
        ~PresidentialPardonForm();
    
        void execute(Bureaucrat const & executor) const;
    
    private:

        PresidentialPardonForm(void);
        PresidentialPardonForm &operator=(PresidentialPardonForm &src);
        
        std::string _target;
};

# endif