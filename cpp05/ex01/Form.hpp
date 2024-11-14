#include "Bureaucrat.hpp"

#ifndef FORM_HPP
#define FORM_HPP

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;

    public:
        // Canonical form:
        Form();
        Form(const std::string name, int signGrade, int execGrade);
        Form(const Form &copy);
        Form &operator=(const Form &op);
        ~Form();

        // Getters:
        const std::string &getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        // Methods:
        void beSigned(const Bureaucrat &bureaucrat);
        void signForm(const Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif