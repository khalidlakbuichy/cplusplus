#include "AForm.hpp"

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

class PresidentialPardonForm : public AForm
{
    private:
        const std::string _target;

    public:
        // Canonical form:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &op);
        ~PresidentialPardonForm();

        // Getters:
        std::string getTarget() const;

        // Methods:
        void execute(Bureaucrat const &executor) const;
};

#endif