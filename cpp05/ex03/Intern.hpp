#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

#ifndef INTERN_HPP
#define INTERN_HPP

class Intern
{
    public:
        // Canonical form:
        Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &other);
        ~Intern();

        //Exception:
        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char *what() const throw() { return ("Form not found"); }
        };

        // Methods:
        AForm *makeForm(const std::string formName, const std::string target);
};

#endif