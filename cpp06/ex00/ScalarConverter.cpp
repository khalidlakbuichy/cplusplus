#include "ScalarConverter.hpp"

// Canocical Form:
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &other) { 
    if (this != &other)
        *this = other; 
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
    if (this != &other)
        *this = other;
    return *this; 
}
ScalarConverter::~ScalarConverter() {}

// heplful function:
ScalarType ScalarConverter::getType(std::string &input)
{
    if (input.length() == 1 && !isdigit(input[0]))
        return CHAR;
    else if (input.length() > 1 && !input.find_first_not_of("0123456789"))
        return INT;
    else if (input.find_first_of("f") != std::string::npos)
        return FLOAT;
    else if (input == "nan" || input == "+inf" || input == "-inf" || input == "nanf" || input == "-inff" || input == "+inff")
        return PSUEDO_LITERAL;
    else if (input.find_first_of(".") != std::string::npos)
        return DOUBLE;
    else
        return INVALID;
}

void ScalarConverter::convertChar(std::string &input)
{
    char c = input[0];
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(std::string &input)
{
    int i = atoi(input.c_str());
    std::cout << "char: ";
    if (i >= 32 && i <= 126)
        std::cout << static_cast<char>(i) << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFloat(std::string &input)
{
    float f = atof(input.c_str());
    std::cout << "char: ";
    if (f >= 32 && f <= 126)
        std::cout << static_cast<char>(f) << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: ";
    if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
        std::cout << static_cast<int>(f) << std::endl;
    else
        std::cout << "impossible !" << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
}

void ScalarConverter::convertDouble(std::string &input)
{
    double d = atof(input.c_str());
    std::cout << "char: ";
    if (d >= 32 && d <= 126)
        std::cout << static_cast<char>(d) << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: ";
    if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
        std::cout << static_cast<int>(d) << std::endl;
    else
        std::cout << "impossible !" << std::endl;
    std::cout << "float: ";
    if (d >= std::numeric_limits<float>::min() && d <= std::numeric_limits<float>::max())
        std::cout << static_cast<float>(d) << "f" << std::endl;
    else
        std::cout << "impossible !" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertPseudoLiteral(std::string &input)
{
    if (input == "nan" || input == "nanf")
    {
        std::cout << "char: impossible !" << std::endl;
        std::cout << "int: impossible !" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (input == "+inf" || input == "+inff")
    {
        std::cout << "char: impossible !" << std::endl;
        std::cout << "int: impossible !" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
    else if (input == "-inf" || input == "-inff")
    {
        std::cout << "char: impossible !" << std::endl;
        std::cout << "int: impossible !" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

// Static Method:
void ScalarConverter::convert(std::string &input)
{
    if (getType(input) == CHAR)
        convertChar(input);
    else if (getType(input) == INT)
        convertInt(input);
    else if (getType(input) == FLOAT)
        convertFloat(input);
    else if (getType(input) == DOUBLE)
        convertDouble(input);
    else if (getType(input) == PSUEDO_LITERAL)
        convertPseudoLiteral(input);
    else if (getType(input) == INVALID)
        std::cout << "Invalid input" << std::endl;
}