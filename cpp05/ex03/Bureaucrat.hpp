#include <string>
#include <iostream>
#include <stdexcept>

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Form;
class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        // Canonical form:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &op);
        ~Bureaucrat();

        // Getters:
        std::string getName() const;
        int getGrade() const;

        // Methods:
        void incrementGrade();
        void decrementGrade();

        // Exceptions:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif