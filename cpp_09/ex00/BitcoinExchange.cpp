# include "BitcoinExchange.hpp"

/* =============== Constructors ================== */

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {(void) src;}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {(void) src; return (*this);}
BitcoinExchange::~BitcoinExchange(){}

/* =============== Methods ================== */

float BitcoinExchange::checkValue(const std::string &str)
{
    std::string sub = str.substr(11);
    
    float value = std::strtof(sub.c_str(), NULL);

    // if (value > 1000)
    //     throw BitcoinExchange::MultiplierTooHighException();
    return (value);
}

void BitcoinExchange::checkDate(const std::string &date)
{
    int month = static_cast<int>(std::strtof((date.substr(5, 2)).c_str(), NULL));
    int day = static_cast<int>(std::strtof((date.substr(8, 2).c_str()), NULL));

    if (month < 1 || month > 12)
        throw BitcoinExchange::ImpossibleDateException();
    
    if (day == 0)
        throw BitcoinExchange::ImpossibleDateException();

    switch (month)
    {
        case 2:
            if (day > 28)
                throw BitcoinExchange::ImpossibleDateException();
        break;

        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30)
                throw BitcoinExchange::ImpossibleDateException();
    default:
            if (day > 31)
                throw BitcoinExchange::ImpossibleDateException();
        break;
    }

}

void BitcoinExchange::parser(const std::string &line)
{
    int i = 0;

    for (; i < 4; i++)
        if (!std::isdigit(line[i]))
            throw BitcoinExchange::WrongValueException();
    if (line[i++] != '-')
        throw BitcoinExchange::WrongValueException();
    for (; i < 7; i++)
        if (!std::isdigit(line[i]))
            throw BitcoinExchange::WrongValueException();
    if (line[i++] != '-')
        throw BitcoinExchange::WrongValueException();
    for (; i < 10; i++)
        if (!std::isdigit(line[i]))
            throw BitcoinExchange::WrongValueException();
    if (line[i++] != ',')
        throw BitcoinExchange::WrongValueException();
    while(line[i] && std::isdigit(line[i]))
        i++;
    if (!line[i])
        return ;
    if (line[i] == '.')
        while(line[++i] && std::isdigit(line[i]))
            ;
    if (line[i])
        throw BitcoinExchange::WrongValueException();
}

void BitcoinExchange::extractDataBase()
{
    std::ifstream ifs("data.csv");
    std::string buffer;

    if (ifs.fail())
        throw BitcoinExchange::FileOpeningError();
    std::getline(ifs, buffer);
    while (1)
    {
        std::getline(ifs, buffer);
        if (ifs.eof())
            break ;
        // std::cout << buffer << std::endl;
        parser(buffer);
        checkValue(buffer);
        // std::cout << buffer.substr(0, 10) << ": " << checkValue(buffer) << std::endl;
        _bitcoinMap[buffer.substr(0, 10)] = checkValue(buffer);
    }
    
    std::cout << "map size: " << _bitcoinMap.size() << std::endl;
    
    std::map<std::string, float>::iterator it = _bitcoinMap.begin();

    for (; it != _bitcoinMap.end(); it++)
        std::cout << it->first << ": " << it->second << std::endl;
}

/* =============== Exceptions ================== */

const char *BitcoinExchange::WrongValueException::what(void) const throw()
{
    return("invalid input\n");
}

const char *BitcoinExchange::MultiplierTooHighException::what(void) const throw()
{
    return("Multiplier too high\n");
}

const char *BitcoinExchange::ImpossibleDateException::what(void) const throw()
{
    return("Non Existing date\n");
}

const char *BitcoinExchange::FileOpeningError::what(void) const throw()
{
    return("File opening error\n");
}