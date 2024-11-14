#include "AForm.hpp"

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

class RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;

    public:
        // Canonical form:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &op);
        ~RobotomyRequestForm();

        // Getters:
        std::string getTarget() const;

        // Methods:
        void execute(Bureaucrat const &executor) const;
};

#endif