# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <cmath>
# include <errno.h>
# include <iomanip>
# include <limits.h>

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

enum
{
    ERROR,
    PSEUDO,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
};

class ScalarConverter
{
    public:

        static void     converter(std::string &value);


    private:

        ScalarConverter(void);
        ScalarConverter(ScalarConverter &src);
        ScalarConverter &operator=(ScalarConverter &src);
        ~ScalarConverter();

};

# endif