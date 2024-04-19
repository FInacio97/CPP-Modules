# include "ScalarConverter.hpp"

/*+++++++++++++++ ||    Orthodox Canonical Form    || ++++++++++++++++*/

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &src) {(void) src;}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &src) {(void) src; return (*this);}

ScalarConverter::~ScalarConverter(){}



/*+++++++++++++++ ||    Convertion and Parsing     || ++++++++++++++++*/

static bool isPseudo(std::string &value, int &state)
{
        // std::cout << value.compare("+inff") << "\n";
        // std::cout << value.compare("-inff") << "\n";
        // std::cout << value.compare("nanf") << "\n";
        // std::cout << value.compare("+inf") << "\n";
        // std::cout << value.compare("-inf") << "\n";
        // std::cout << value.compare("nan") << "\n";
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
    if (value.length() == 1 && std::isalpha(*(value.c_str())))
    {
        state = CHAR;
        return (true);
    }
    return (false);
}

static void trimEnd(std::string &str)
{
    int len = str.length();

    while (--len && std::isspace(str[len]))
        ;
    str[++len] = 0;
}

static bool isNumber(std::string &value, int &state)
{
    int i = 0;

    trimEnd(value);

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
        std::cout << value[i] << std::endl;
        if (value[i] == 'f' && !value[i + 1])
            state = FLOAT;
        else if (!value[i])
            state = DOUBLE;
        else
        {
            std::cout << "cenas\n";
            return (false);
    }
    else 
        return (false);

    return (true);

}

void ScalarConverter::converter(std::string &value)
{
    int state = 0;

    if (!value.length())
        std::cerr << RED << "Error: empty string\n" << RESET;

    if (isPseudo(value, state) || isChar(value, state) || isNumber(value, state))
    {
        switch (state)
        {
        case ERROR:
            std::cout << "Error\n";
            break;

        case PSEUDO:
            std::cout << "Pseudo\n";
            break;

        case CHAR:
            std::cout << "Char\n";
            break;

        case INT:
            std::cout << "Int\n";
            break;

        case FLOAT:
            std::cout << "Float\n";
            break;
        
        case DOUBLE:
            std::cout << "Double\n";
            break;

        default:
            std::cout << "No waaaaay...\n";
            break;
        }
    }
    else
        std::cerr << RED << "Error: invalid input\n" << RESET;
}

/*
    test: ".039"

*/