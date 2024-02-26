# include "Fixed.hpp"

// Constructors

Fixed::Fixed(void):_fixed_point_val(0)
{
	std::cout << YELLOW <<"Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &to_copy)
{
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	*this = to_copy;
}

Fixed::Fixed(const int n)
{
	int res;

	std::cout << YELLOW << "Int constructor called" << RESET << std::endl;

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
	std::cout << YELLOW << "Float constructor called" << RESET << std::endl;

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
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	this->_fixed_point_val = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << YELLOW << "Distructor called" << RESET << std::endl;
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
	std::cout << CYAN << "setRawBits member function called" << RESET << std::endl;
	this->_fixed_point_val = raw;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
