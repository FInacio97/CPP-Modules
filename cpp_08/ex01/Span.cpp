# include "Span.hpp"

/* ===============| Constructors |=================== */

Span::Span() : _size(0), _minSpan(-1), _newNmbr(false) {
    std::srand(std::time(NULL));
}

Span::Span(const Span &src)
{
    std::srand(std::time(NULL));
    *this = src;
}

Span::Span(const unsigned int N) : _size(N), _minSpan(-1), _newNmbr(false) {
    std::srand(std::time(NULL));
}

Span &Span::operator=(const Span &src)
{
    if (this == &src)
        return (*this);
    
    this->_size = src._size;
    this->_minSpan = src._minSpan;
    this->_newNmbr = src._newNmbr;

    this->_vector.resize(src._vector.size());
    std::copy(src._vector.begin(), src._vector.end(), this->_vector.begin());

    return (*this);
}

Span::~Span(void) {}

/* ===============| Other Methods |=================== */

void Span::addNumber(const int value)
{
    if (_vector.size() >= _size)
        throw std::exception();
    _vector.push_back(value);
    std::sort(_vector.begin(), _vector.begin() + _vector.size());
    _newNmbr = true;
}

int Span::longestSpan()
{
    if (_vector.size() < 2)
        throw std::exception();
    return (*(_vector.end() - 1) - *(_vector.begin()));
}

int Span::shortestSpan()
{
    int diff;
    std::vector<int>::iterator it;

    if (_vector.size() < 2)
        throw std::exception();

    if (!_newNmbr)
    {
        _newNmbr = false;
        return (_minSpan);
    }
    if (_minSpan == -1)
        _minSpan = *(_vector.begin() + 1) - *(_vector.begin()); 
          
    for (it = _vector.begin(); it != (_vector.end() - 1); ++it)
    {
        diff = *(it + 1) - *it;
        if (diff < _minSpan)
            _minSpan = diff;
    }
    return (_minSpan);
}

int Span::generate()
{
    return (std::rand() % RAND_RANGE);
}

void Span::addRandom(const unsigned int amount)
{
    if (_size < amount)
    {
        std::cerr << "vector doesnt have enough capacity\n";
        return ;
    }

    _vector.resize(amount);
    std::generate(_vector.begin(), _vector.end(), generate);
    std::sort(_vector.begin(), _vector.end());
    _newNmbr = true;
}

void Span::displayArray()
{
    int i = 0;
    std::vector<int>::iterator it;

    for (it = _vector.begin(); it != _vector.end(); it++)
         std::cout << "element[" << i++ << "]: " << *it << std::endl; 
}

