#include "Bureaucrat.hpp"

int main (void)
{
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);
    Bureaucrat b3("b3", 75);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;

    // Trying to test the exceptions in the constructor:
    try
    {
        Bureaucrat b4("b4", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b5("b5", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Trying to test the exceptions in the incrementGrade and decrementGrade methods:
    try
    {
        Bureaucrat b6("b6", 1);
        b6.incrementGrade();
        std::cout << b6 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b7("b7", 150);
        b7.decrementGrade();
        std::cout << b7 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}