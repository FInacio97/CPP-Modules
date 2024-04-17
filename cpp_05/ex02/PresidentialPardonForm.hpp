# ifndef PRESITENTIALPARDONFORM_HPP
# define PRESITENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:

        PresidentialPardonForm(&src);
        PresidentialPardonForm(const std::string &target);
        ~PresidentialPardonForm();
    
    private:

        PresidentialPardonForm(void);
        PresidentialPardonForm &operator=(PresidentialPardonForm &src);
        void execute(Bureaucrat const & executor) const;
        
        std::string _target;
};

# endif