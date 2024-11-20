#include "Form.hpp"

// Canonical form:
Form::Form() : _name("unknown"), _signed(false), _signGrade(150), _execGrade(150) {}
Form::Form(const std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    try
    {
        if (signGrade < 1 || execGrade < 1)
            throw Form::GradeTooHighException();
        if (signGrade > 150 || execGrade > 150)
            throw Form::GradeTooLowException();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {}
Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        *this = Form(other);
    }
    return (*this);
}
Form::~Form() {};

// Getters:
const std::string &Form::getName() const { return (_name); }
bool Form::getSigned() const { return (_signed); }
int Form::getSignGrade() const { return (_signGrade); }
int Form::getExecGrade() const { return (_execGrade); }

// Methods:
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw Form::GradeTooLowException();
    _signed = true;
}

// Exceptions:
const char *Form::GradeTooHighException::what() const throw() { return ("Grade is too high"); }
const char *Form::GradeTooLowException::what() const throw() { return ("Grade is too low"); }

// Operator overloads:
std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute";
    return (out);
}
