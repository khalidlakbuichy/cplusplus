#include <cstdlib>
#include "Bureaucrat.hpp"

#ifndef AFORM_HPP
#define AFORM_HPP

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;

    public:
        // Canonical form:
        AForm();
        AForm(const std::string name, int signGrade, int execGrade);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &op);
        ~AForm();

        // Getters:
        std::string getName() const;
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
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        //execute method:
        // It's important to make this as a pure virtual method, because if we didn't so we can't call it an Abstract class.
        virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif