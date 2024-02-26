# include <iostream>
# include <string>
# include <cmath>

# ifndef FIXED
# define FIXED

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

class Fixed
{
	public:

		Fixed(void);
		Fixed(const Fixed &to_copy);
		Fixed(const int n);
		Fixed(const float n);

		Fixed &operator=(const Fixed &rhs);
		~Fixed(void);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;


	private:

		int 				_fixed_point_val;
		static const int	_frac_bits = 8;

};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs); // why cant this be a member function?

# endif

/*

a = b = c = d;

*/