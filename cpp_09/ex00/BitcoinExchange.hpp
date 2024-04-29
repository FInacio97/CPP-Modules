# ifndef BICOINEXCHANGE_HPP
# define BICOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <cerrno>
# include <cmath>
# include <cmath>
# include <iomanip>

class BitcoinExchange
{
    public:

        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange(void);

        void checkDate(const std::string &date);
        float checkValue(const std::string &str, bool isDB);
        void parserDB(const std::string &line);
        void parserInput(std::string &line);

        void extractDB();
        void displayMap();
        void Exchange(char *path);

        // Exceptions

        class MultiplierTooHighException : public std::exception{
            const char *what(void) const throw();
        };
        
        class FileOpeningError : public std::exception{
            const char *what(void) const throw();
        };
        
        class FloatOverFlow : public std::exception{
            const char *what(void) const throw();
        };
        
        class BadInputException : public std::exception{
            public:
                BadInputException(const std::string &date);
                virtual ~BadInputException() throw ();
                const char *what() const throw();
            private:
                std::string _err;
        };
        
        class NegativeException : public std::exception{
            const char *what() const throw();
        };
    private:

        std::map<std::string, float> _bitcoinMap;
};

# endif