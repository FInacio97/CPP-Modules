# ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <exception>
# include <iostream>
# include <vector>
# include <ctime>
# include <climits>

class Span
{
    public:

        Span(unsigned int N);
        ~Span(void);

        void addNumber(const int value);
        void addRandom(const unsigned int Amount);
        int shortestSpan();
        int longestSpan();

        void displayArray();
        static int generate();

    private:

        Span(void);
        Span(Span &src);
        Span &operator=(Span &src);


        std::vector<int> _vector;
        unsigned int    _size;
        int             _minSpan;
        bool            _newNmbr;
};

# endif