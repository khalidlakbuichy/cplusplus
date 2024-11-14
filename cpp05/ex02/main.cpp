#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main (void)
{
    // Simple tests:
    Bureaucrat president("president", 1);
    Bureaucrat robot("robot", 45);
    Bureaucrat gardener("gardener", 137);

    PresidentialPardonForm ppf("ppf");
    RobotomyRequestForm rrf("rrf");
    ShrubberyCreationForm scf("scf");

    ppf.signForm(president);
    ppf.execute(president);
    rrf.signForm(robot);
    rrf.execute(robot);
    scf.signForm(gardener);
    scf.execute(gardener);

    // Exceptions tests:
    try
    {
        PresidentialPardonForm ppf2("ppf2");
        ppf2.execute(president);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        RobotomyRequestForm rrf2("rrf2");
        rrf2.execute(robot);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        ShrubberyCreationForm scf2("scf2");
        scf2.execute(gardener);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

}