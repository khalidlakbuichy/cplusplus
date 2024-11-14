#include "Intern.hpp"

int main (void)
{
    Intern intern;
    AForm *form;

    form = intern.makeForm("robotomy request", "target1");
    form->execute(Bureaucrat("b1", 1));
    delete form;

    form = intern.makeForm("shrubbery creation", "target2");
    form->execute(Bureaucrat("b2", 1));
    delete form;

    form = intern.makeForm("presidential pardon", "target3");
    form->execute(Bureaucrat("b3", 1));
    delete form;

    try
    {
        form = intern.makeForm("unknown", "target4");
        form->execute(Bureaucrat("b4", 1));
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}