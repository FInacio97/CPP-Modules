# include "Fixed.hpp"

// Constructors

Fixed::Fixed(void):_fixed_point_val(0)
{
	// std::cout << YELLOW <<"Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &to_copy)
{
	// std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	*this = to_copy;
}

Fixed::Fixed(const int n)
{
	int res;

	// std::cout << YELLOW << "Int constructor called" << RESET << std::endl;

	if (n > 8388607 || n < -8388607)
	{
		this->_fixed_point_val = 0;
		std::cout << RED << "Number out of range!" << std::endl;
		return ;
	}
	res = n << this->_frac_bits;
	this->_fixed_point_val = res;
}

Fixed::Fixed(const float n)
{
	// std::cout << YELLOW << "Float constructor called" << RESET << std::endl;

	if (n >= 8388608 || n <= -8388600)
	{
		this->_fixed_point_val = 0;
		std::cout << RED << "Number out of range!" << std::endl;
		return ;
	}
	this->_fixed_point_val = roundf(n * (1 << this->_frac_bits));
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	// std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	this->_fixed_point_val = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	// std::cout << YELLOW << "destructor called" << RESET << std::endl;
}

float Fixed::toFloat( void ) const
{
	float res;

	res = (float) _fixed_point_val;
	res /= (1 << this->_frac_bits);
	return (res);
}

int Fixed::toInt( void ) const
{
	return (this->_fixed_point_val >> this->_frac_bits);
}

int Fixed::getRawBits(void) const
{
	return (this->_fixed_point_val);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << CYAN << "setRawBits member function called" << RESET << std::endl;
	this->_fixed_point_val = raw;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

/* =============== | Comparison operators | =============== */

int Fixed::operator==(const Fixed &to_compare) const
{
	if (this->_fixed_point_val == to_compare.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator!=(const Fixed &to_compare) const
{
	if (this->_fixed_point_val != to_compare.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<(const Fixed &to_compare) const
{
	if (this->_fixed_point_val < to_compare.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<=(const Fixed &to_compare) const
{
	if (this->_fixed_point_val <= to_compare.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator>(const Fixed &to_compare) const
{
	if (this->_fixed_point_val > to_compare.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator>=(const Fixed &to_compare) const
{
	if (this->_fixed_point_val > to_compare.getRawBits())
		return (1);
	return (0);
}

/* =============== | Arithmetic operators | =============== */

Fixed Fixed::operator+(const Fixed &operand) const
{
	Fixed res;

	res._fixed_point_val = this->_fixed_point_val + operand._fixed_point_val;
	return (res);
}

Fixed Fixed::operator-(const Fixed &operand) const
{
	Fixed res;

	res._fixed_point_val = this->_fixed_point_val - operand._fixed_point_val;
	return (res);
}

Fixed Fixed::operator*(const Fixed &operand) const
{
	float mult;

	mult = this->toFloat() * operand.toFloat();
	Fixed res(mult);
	return (res);
}

Fixed Fixed::operator/(const Fixed &operand) const
{
	float div;

	div = this->toFloat() / operand.toFloat();
	Fixed res(div);
	return (res);
}

/* =============== | Increment and decrement operators | =============== */

Fixed &Fixed::operator++()
{
	_fixed_point_val++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed res = *this;

	_fixed_point_val++;
	return (res);
}

Fixed &Fixed::operator--()
{
	_fixed_point_val--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed res = *this;

	_fixed_point_val--;
	return (res);
}

/* =============== | Min and max operators | =============== */

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f2);
	return (f1);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f2);
	return (f1);
}