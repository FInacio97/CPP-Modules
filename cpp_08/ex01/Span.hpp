# ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <exception>
# include <iostream>
# include <vector>
# include <ctime>
# include <climits>

# define RAND_RANGE 1000000000

class Span
{
    public:

        Span();
        Span(const unsigned int N);
        Span(const Span &src);
        Span &operator=(const Span &src);
        ~Span(void);

        void addNumber(const int value);
        void addRandom(const unsigned int Amount);
        int shortestSpan();
        int longestSpan();

        void displayArray();
        static int generate();

    private:

        std::vector<int> _vector;
        unsigned int    _size;
        int             _minSpan;
        bool            _newNmbr;
};

# endif