#include "Bureaucrat.hpp"

// Canonical form:
Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    // self-assignment guard
    if (this == &other)
        return (*this);
    _grade = other._grade;
    return (*this);
}
Bureaucrat::~Bureaucrat() {};

// Getters:
std::string Bureaucrat::getName() const { return (_name); }
int Bureaucrat::getGrade() const { return (_grade); }

// Methods:
void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}
void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

// Exceptions:
const char *Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade is too high"); }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade is too low"); }

// Operator overloads:
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}