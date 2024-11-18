#include "Intern.hpp"

int main (void)
{
    Intern intern;
    Bureaucrat bureaucrat("Bureaucrat", 1);

    try
    {
        AForm *form = intern.makeForm("robotomy request", "target");
        form->beSigned(bureaucrat);
        form->execute(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    Intern intern2;
    Bureaucrat bureaucrat2("Bureaucrat2", 2);
    try
    {
        AForm *form = intern2.makeForm("shrubbery creation", "target");
        form->beSigned(bureaucrat2);
        form->execute(bureaucrat2);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    Intern intern3;
    Bureaucrat bureaucrat3("Bureaucrat3", 3);
    try
    {
        AForm *form = intern3.makeForm("presidential pardon", "target");
        form->beSigned(bureaucrat3);
        form->execute(bureaucrat3);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}