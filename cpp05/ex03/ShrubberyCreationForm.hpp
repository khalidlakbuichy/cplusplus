#include "AForm.hpp"
#include <fstream>

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;

    public:
        // Canonical form:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &op);
        ~ShrubberyCreationForm();

        // Getters:
        std::string getTarget() const;

        // Methods:
        void execute(Bureaucrat const &executor) const;
};

#endif