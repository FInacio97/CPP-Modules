# include "Span.hpp"

/* ===============| Constructors |=================== */

Span::Span(void) : _size(0), _minSpan(-1), _newNmbr(false) {}

Span::Span(Span &src) : _size(0), _minSpan(-1), _newNmbr(false)
{
    (void) src; 
}

Span::Span(unsigned int N) : _size(N), _minSpan(-1), _newNmbr(false) {}

Span &Span::operator=(Span &src)
{   
    (void) src;
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
    return (std::rand() % 10000);
}

void Span::addRandom(const unsigned int amount)
{
    if ((_size - _vector.size()) < amount)
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

