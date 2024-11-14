#include "RobotomyRequestForm.hpp"

// Canonical form:
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("unknown") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        *this = RobotomyRequestForm(other);
    }
    return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm() {};

// Getters:
std::string RobotomyRequestForm::getTarget() const { return (_target); }

// Methods:
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::cout << "** DRILLING NOISE **" << std::endl;
    if (rand() % 2) // Generate a random number between 0 and 1
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << _target << " robotomization failed" << std::endl;
}