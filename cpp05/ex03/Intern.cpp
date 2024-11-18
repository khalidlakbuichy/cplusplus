#include "Intern.hpp"


// Canonical form:
Intern::Intern() {}
Intern::Intern(const Intern &copy) { *this = copy; }
Intern &Intern::operator=(const Intern &other)
{
    if (this != &other)
    {
        *this = Intern(other);
    }
    return (*this);
}
Intern::~Intern() {
    for (int i = 0; i < 3; i++)
    {
        delete forms[i];
    }
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string formNames[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

    forms[0] = new RobotomyRequestForm(target);
    forms[1] = new ShrubberyCreationForm(target);
    forms[2] = new PresidentialPardonForm(target);

    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (forms[i]);
        }
    }
    throw Intern::FormNotFoundException();
    return (NULL);
}