# include <iostream>
# include <string>

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
		Fixed &operator=(const Fixed &rhs);
		~Fixed(void);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:

		int 				_fixed_point_val;
		static const int	_frac_bits = 8;

};


# endif