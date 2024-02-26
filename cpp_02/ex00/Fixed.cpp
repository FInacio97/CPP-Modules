# include "Fixed.hpp"

Fixed::Fixed(void):_fixed_point_val(0)
{
	std::cout << YELLOW <<"Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &to_copy)
{
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	*this = to_copy;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	this->_fixed_point_val = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << YELLOW << "Distructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << CYAN << "getRawBits member function called" << RESET << std::endl;
	return (this->_fixed_point_val);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << CYAN << "setRawBits member function called" << RESET << std::endl;
	this->_fixed_point_val = raw;
}