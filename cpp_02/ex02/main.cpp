#include "Fixed.hpp"


int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}


// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c( 42.125f );
// 	Fixed const d( b );

// 	a = Fixed( 1234.4321f );

// 	if (a != b)
// 		std::cout << "a(" << a.toFloat() << ") is equal to b(" << b.toFloat() << ")" << std::endl;
// 	else
// 		std::cout << "a(" << a.toFloat() << ") is not equal to b(" << b.toFloat() << ")" << std::endl;
// 	if (d != b)
// 		std::cout << "d(" << d.toFloat() << ") is equal to b(" << b.toFloat() << ")" << std::endl;
// 	else
// 		std::cout << "d(" << d.toFloat() << ") is not equal to b(" << b.toFloat() << ")" << std::endl;

// 	// Arithmetics

// 	Fixed e;

// 	e = a / b;
// 	std::cout << "e = " << e << std::endl;


// 	Fixed n(1);

// 	std::cout << n << std::endl;
// 	std::cout << ++n << std::endl;
// 	std::cout << n << std::endl;
// 	std::cout << n++ << std::endl;
// 	std::cout << n << std::endl;
// 	std::cout << --n << std::endl;
// 	std::cout << n << std::endl;
// 	std::cout << n-- << std::endl;
// 	std::cout << n << std::endl;

// 	return 0;
// }