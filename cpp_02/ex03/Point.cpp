# include "Point.hpp"

Point::Point(void):x(0), y(0) {}

Point::Point(const float x, const float y): x(x), y(y) {}

Point::Point(const Point &src): x(src.x), y(src.y)
{
}

Point &Point::operator=(const Point &)
{
	return (*this);
}

Point::~Point(void) {}

const Fixed &Point::getX(void) const
{
	return (x);
}

const Fixed &Point::getY(void) const
{
	return (y);
}
