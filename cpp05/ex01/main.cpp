#include "Form.hpp"

#define BOLD   "\033[1m"
#define RESET   "\033[0m"

int main (void)
{
    //Building the objects:
    std::cout << BOLD "Building the objects:" RESET << std::endl;
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);
    Bureaucrat b3("b3", 75);
    
    Form f1("f1", 1, 1);
    Form f2("f2", 150, 150);
    Form f3("f3", 75, 75);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    std::cout << "=================================================" << std::endl << std::endl;

    // Trying to test the exceptions in the constructor:

    std::cout << BOLD "Trying to test the exceptions in the constructor:" RESET << std::endl;
    try
    {
        Form f4("f4", 0, 0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form f5("f5", 151, 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "=================================================" << std::endl << std::endl;

    // Trying to test the exceptions in the beSigned method:
    std::cout << BOLD "Trying to test the exceptions in the beSigned method:" RESET << std::endl;
    try
    {
        f1.beSigned(b2);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        f2.beSigned(b1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
        try
    {
        f3.beSigned(b3);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "=================================================" << std::endl << std::endl;

    // Now let's see which form is signed successfully:
    std::cout << BOLD "Now let's see which form is signed successfully:" RESET << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;
    std::cout << "=================================================" << std::endl << std::endl;


    // Trying to test the exceptions in the signForm method:
    std::cout << BOLD "Trying to test the exceptions in the signForm method:" RESET << std::endl;
    b1.signForm(f1);
    b2.signForm(f2);
    b3.signForm(f3);

}