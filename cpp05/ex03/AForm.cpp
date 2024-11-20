#include "AForm.hpp"

// Canonical form:
AForm::AForm() : _name("unknown"), _signed(false), _signGrade(150), _execGrade(150) {}
AForm::AForm(const std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    try
    {
        if (signGrade < 1 || execGrade < 1)
            throw AForm::GradeTooHighException();
        if (signGrade > 150 || execGrade > 150)
            throw AForm::GradeTooLowException();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {}
AForm &AForm::operator=(const AForm &other)
{
   if (this != &other)
    {
        _signed = other._signed;
    }
    return (*this);
}
AForm::~AForm() {};

// Getters:
std::string AForm::getName() const { return (_name); }
bool AForm::getSigned() const { return (_signed); }
int AForm::getSignGrade() const { return (_signGrade); }
int AForm::getExecGrade() const { return (_execGrade); }

// Methods:
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw AForm::GradeTooLowException();
    _signed = true;
}
void AForm::signForm(const Bureaucrat &bureaucrat)
{
    try
    {
        beSigned(bureaucrat);
        std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << bureaucrat.getName() << " cannot sign " << _name << " because " << e.what() << std::endl;
    }
}

// Exceptions:
const char *AForm::GradeTooHighException::what() const throw() { return ("Grade is too high"); }
const char *AForm::GradeTooLowException::what() const throw() { return ("Grade is too low"); }
const char *AForm::FormNotSignedException::what() const throw() { return ("Form is not signed"); }

// Operator overloads:
std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute";
    return (out);
}
