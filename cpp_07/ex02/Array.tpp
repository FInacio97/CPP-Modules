# ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(const Array &src) : _array(NULL), _size(0)
{
    *this = src;
}

template <typename T>
Array<T>::Array(unsigned int n)  : _array(new T[n]), _size(n)
{
    for (unsigned int i = 0; i < n; i++)
        _array[i] = 0;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
    if (this == &src)
        return (*this);
    if (this->_array)
        delete []this->_array;
    this->_size = src._size;
    this->_array = new T[this->_size];
    for (size_t i = 0; i < this->_size; i++)
        this->_array[i] = src._array[i];
    return(*this);
}

template <typename T>
T	&Array<T>::operator[](const size_t i)
{
    if (i >= _size)
        throw OutOfBoundsException();
    return (_array[i]);
}

template <typename T>
const T	&Array<T>::operator[](const size_t i) const
{
    if (i >= _size)
        throw OutOfBoundsException();
    return (_array[i]);
}

template <typename T>
Array<  T>::~Array(void)
{
    delete [] _array;
}

template <typename T>
unsigned int Array<T>::size() const {return (_size);}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
    return ("Index out of bounds");
}

# endif