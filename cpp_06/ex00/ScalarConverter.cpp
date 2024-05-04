# include "ScalarConverter.hpp"

/*+++++++++++++++ ||    Orthodox Canonical Form    || ++++++++++++++++*/

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &src) {(void) src;}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &src) {(void) src; return (*this);}

ScalarConverter::~ScalarConverter(){}



/*+++++++++++++++ ||    Convertion and Parsing     || ++++++++++++++++*/ // TODO: all these fucntion shoul be methods of the class. Why do u have them as just fucntions. this is not C

static void trimEnd(std::string &str)
{
    int len = str.length();

    while (--len && std::isspace(str[len]))
        ;
    str[++len] = 0;
}

static bool isPseudo(std::string &value, int &state)
{
    if (!value.compare("+inff") || !value.compare("-inff") || !value.compare("nanf")
            || !value.compare("+inf") || !value.compare("-inf") || !value.compare("nan"))
    {
        state = PSEUDO;
        return (true);
    }
    return (false); 
}

static bool isChar(std::string &value, int &state)
{
    if (value.length() == 1 && !std::isdigit(*(value.c_str())))
    {
        state = CHAR;
        return (true);
    }
    return (false);
}

static bool isNumber(std::string &value, int &state)
{
    int i = 0;
    int digit_flag = 0;

    trimEnd(value);

    while (value[i])
        if (std::isdigit(value[i++]))
        {
            digit_flag++;
            i = 0;
            break ;
        }
    if (!digit_flag)
        return (false);

    while (value[i] && std::isspace(value[i]))
        i++;

    if (value[i] == '+' || value[i] == '-')
        i++;

    while (value[i] && std::isdigit(value[i]))
        i++;

    if (!value[i])
        state = INT;
    else if (value[i] == '.')
    {
        i++;
        while (value[i] && std::isdigit(value[i]))
            i++;
        if (value[i] == 'f' && !value[i + 1])
            state = FLOAT;
        else if (!value[i])
            state = DOUBLE;
        else
            return (false);
    }
    else 
        return (false);
    
    return (true);

}

void displayPseudo(std::string &value)
{
    std::string display;
    if (!value.compare("nan") || !value.compare("nanf"))
        display = "nan";
    else if (!value.compare("+inf") || !value.compare("+inff"))
        display = "+inf";
    else if (!value.compare("-inf") || !value.compare("-inff"))
        display = "-inf";
    
    std::cout << CYAN <<"char: " << PURPLE << "impossible\n" << RESET;
    std::cout << CYAN <<"int: " << PURPLE << "impossible\n" << RESET;
    std::cout << CYAN <<"float: " << display << "f\n" << RESET;
    std::cout << CYAN <<"double: " << display << std::endl << RESET;

}

static void displayChar(std::string &value)
{
    char c = value[0];
    if (std::isprint(c))
        std::cout << CYAN <<"char: " << GREEN << "'" << c << "'\n" << RESET;
    else
        std::cout << CYAN <<"char: " << PURPLE << "Non displayable\n" << RESET;
    
    std::cout << CYAN <<"int: " << GREEN << static_cast<int>(c) << "\n" << RESET;
    std::cout << CYAN <<"float: " << GREEN << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n" << RESET;
    std::cout << CYAN <<"double: " << GREEN << std::fixed << std::setprecision(1) << static_cast<double>(c) << "\n" << RESET;
    
}

static void displayNumber(std::string &value)
{
    bool impossible = true;
    double val = std::strtod(value.c_str(), NULL);

    if (val == HUGE_VAL || val == -HUGE_VAL || errno == ERANGE)
        impossible = false;

    if (!impossible || val <= -129 || val >= 128)
        std::cout << CYAN <<"char: " << PURPLE << "impossible\n" << RESET;
    else
    {
        char c = static_cast<char>(val);
        if (std::isprint(c))
            std::cout << CYAN <<"char: " << GREEN << "'" << c << "'\n" << RESET;
        else
            std::cout << CYAN <<"char: " << PURPLE << "Non displayable\n" << RESET;
    }

    if (!impossible || val < INT_MIN || val > INT_MAX)
        std::cout << CYAN <<"int: " << PURPLE << "impossible\n" << RESET;
    else
        std::cout << CYAN <<"int: " << GREEN << static_cast<int>(val) << "\n" << RESET;
    
    if (!impossible || val < -MAXFLOAT || val > MAXFLOAT)
        std::cout << CYAN <<"float: " << PURPLE << "impossible\n" << RESET;
    else
        std::cout << CYAN <<"float: " << GREEN << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f\n" << RESET;
    
    if (impossible)
        std::cout << CYAN <<"double: " << GREEN << std::fixed << std::setprecision(1) << static_cast<double>(val) << "\n" << RESET;
    else   
        std::cout << CYAN <<"double: " << PURPLE << "impossible\n" << RESET;
}

void ScalarConverter::converter(std::string &value)
{
    int state = 0;

    if (!value.length())
    {
        std::cerr << RED << "Error: empty string\n" << RESET;
        return ;
    }

    if (isPseudo(value, state) || isChar(value, state) || isNumber(value, state))
    {
        switch (state)
        {
        case ERROR:
            std::cout << "Error\n";
            break;

        case PSEUDO:
            displayPseudo(value);
            break;

        case CHAR:
            displayChar(value);
            break;

        default:
            displayNumber(value);
            break;
        }
    }
    else
        std::cerr << RED << "Error: invalid input\n" << RESET;
}
