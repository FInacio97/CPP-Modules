# ifndef BICOINEXCHANGE_HPP
# define BICOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

class BitcoinExchange
{
    public:

        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange(void);

        void checkDate(const std::string &date);
        float checkValue(const std::string &str);
        void parser(const std::string &line);

        void extractDataBase();

        // Exceptions
        class WrongValueException : public std::exception{
            virtual const char *what(void) const throw();
        };
        class MultiplierTooHighException : public std::exception{
            virtual const char *what(void) const throw();
        };
        class ImpossibleDateException : public std::exception{
            virtual const char *what(void) const throw();
        };
        class FileOpeningError : public std::exception{
            virtual const char *what(void) const throw();
        };

    private:

        std::map<std::string, float> _bitcoinMap;
        std::map<std::string, float> _inputMap;
};

# endif