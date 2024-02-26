# include "Fixed.hpp"

# ifndef POINT_HPP
# define POINT_HPP

class Point
{
	public:

		Point(void);
		Point(const float x, const float y);
		Point(const Point &src);
		Point &operator=(const Point &);
		~Point(void);

		const Fixed &getX(void) const;
		const Fixed &getY(void) const;

	private:

		const Fixed x;
		const Fixed y;
};


# endif