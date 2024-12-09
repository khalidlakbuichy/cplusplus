#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

enum ScalarType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSUEDO_LITERAL,
    INVALID
};

class ScalarConverter
{
    // Static Class has all constructor and destructor private:
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter &operator=(ScalarConverter const &other);
        ~ScalarConverter();
        // heplful function:
        static ScalarType getType(const std::string &input);
        static void convertChar(std::string &input);
        static void convertInt(std::string &input);
        static void convertFloat(std::string &input);
        static void convertDouble(std::string &input);
        static void convertPseudoLiteral(std::string &input);

    public:
        static void convert(std::string &input);
    
};

#endif
