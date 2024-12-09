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
ScalarType ScalarConverter::getType(const std::string &input) {
    // Handle empty string
    if (input.empty())
        return INVALID;

    // Handle pseudo literals
    if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
        return PSUEDO_LITERAL;

    // Check for single-character char literals
    if (input.length() == 1 && !std::isdigit(input[0])) {
        return CHAR;
    }

    // Check for valid int
    size_t i = 0;
    if (input[i] == '+' || input[i] == '-') i++; // Skip leading sign
    if (i < input.size() && std::isdigit(input[i])) { // Ensure digits follow the sign
        while (i < input.size() && std::isdigit(input[i])) i++;
        if (i == input.size())
            return INT;
    }

    // Check for valid float
    i = 0;
    if (input[i] == '+' || input[i] == '-') i++; // Skip leading sign
    bool hasDecimalPoint = false;
    while (i < input.size() && (std::isdigit(input[i]) || input[i] == '.')) {
        if (input[i] == '.') {
            if (hasDecimalPoint) return INVALID; // Multiple decimal points
            hasDecimalPoint = true;
        }
        i++;
    }
    if (i < input.size() && input[i] == 'f' && i == input.size() - 1)
        return FLOAT; // Ends with 'f' and valid float format

    // Check for valid double
    if (hasDecimalPoint && i == input.size())
        return DOUBLE; // Valid double without 'f'

    // If no match, return INVALID
    return INVALID;
}

void ScalarConverter::convertChar(std::string &input)
{
    std::cout << "Convert Char" << std::endl;

    char c = input[0];
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(std::string &input)
{
    std::cout << "Convert Int" << std::endl;

    // Converting from string to long:
    long value = std::strtol(input.c_str(), NULL, 10);

    // Check if the value is out of range:
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    // Converting from long to int safely:
    int i = static_cast<int>(value);
    
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
    std::cout << "Convert Float" << std::endl;

    // Converting from string to float:
    float f = std::strtod(input.c_str(), NULL);

    // Check if the char is printable or not:
    std::cout << "char: ";
    if (f >= 32 && f <= 126)
        std::cout << static_cast<char>(f) << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    // Check if the float is out of range:
    std::cout << "int: ";
    if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
        std::cout << static_cast<int>(f) << std::endl;
    else
        std::cout << "impossible" << std::endl;
    
    std::cout << "float: "  << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
}

void ScalarConverter::convertDouble(std::string &input)
{
    std::cout << "Convert Double" << std::endl;

    double d = std::strtod(input.c_str(), NULL);

    // Check if the char is printable or not:
    std::cout << "char: ";
    if (d >= 32 && d <= 126)
        std::cout << static_cast<char>(d) << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    // Check if the double is out of range:
    std::cout << "int: ";
    if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
        std::cout << static_cast<int>(d) << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "float: ";
    if (d >= std::numeric_limits<float>::min() && d <= std::numeric_limits<float>::max())
        std::cout  << static_cast<float>(d) << "f" << std::endl;
    else
        std::cout << "impossible" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertPseudoLiteral(std::string &input)
{
    std::cout << "Convert Pseudo Literal" << std::endl;

    if (input == "nan" || input == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (input == "+inf" || input == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
    else if (input == "-inf" || input == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
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