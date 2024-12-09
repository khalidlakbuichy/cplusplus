#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return 1;
    }
    
    std::string input = av[1];
    ScalarConverter::convert(input);
}