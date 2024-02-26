# include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed ax = a.getX();
	Fixed ay = a.getY();
	Fixed bx = b.getX();
	Fixed by = b.getY();
	Fixed cx = c.getX();
	Fixed cy = c.getY();
	Fixed px = point.getX();
	Fixed py = point.getY();

	if ((ax == bx && bx == cx) || (ay == by && by == cy))
	{
		std::cout << RED << "The points dont make a triangle!" << std::endl;
		return (false);
	}

	if (cy == ay)
		return (bsp(b, a, c, point));

	Fixed v1 = (ax * (cy - ay) + (py - ay) * (cx - ax) - px * (cy - ay))
				/ ((by - ay) * (cx - ax) - (bx - ax) * (cy - ay));
	Fixed v2 = (py - ay - v1 * (by - ay)) / (cy - ay);
	std::cout << YELLOW << "v1: " << v1 << RESET << std::endl;
	std::cout << YELLOW << "v2: " << v2 << RESET << std::endl;
	Fixed v_sum = v1 + v2;
	std::cout << YELLOW << "v_sum: " << v_sum << RESET << std::endl;

	if (v_sum < 1 &&  v_sum > 0 && v1 > 0 && v2 > 0)
		return (true);
	return (false);
}

// bool bsp( Point const a, Point const b, Point const c, Point const point)
// {
//     Fixed Ax = a.getX();
// 	std::cout << "Ax: " << a.getX() << std::endl;
//     Fixed Ay = a.getY();
// 	std::cout << "Ay: " << Ay << std::endl;
//     Fixed Bx = b.getX();
// 	std::cout << "Bx: " << Bx << std::endl;
//     Fixed By = b.getY();
// 	std::cout << "By: " << By << std::endl;
//     Fixed Cx = c.getX();
// 	std::cout << "Cx: " << Cx << std::endl;
//     Fixed Cy = c.getY();
// 	std::cout << "Cy: " << Cy << std::endl;
//     Fixed Px = point.getX();
// 	std::cout << "Px: " << Px << std::endl;
//     Fixed Py = point.getY();
// 	std::cout << "Py: " << Py << std::endl;


//     Fixed w1_numerator = Ax * (Cy - Ay) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay);
// 	std::cout << "w1 numerator: " << w1_numerator << std::endl;
//     Fixed w1_denominator = (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay);
// 	std::cout << "w1 denominator: " << w1_denominator << std::endl;
//     Fixed w1 = w1_numerator / w1_denominator;

//     Fixed w2_numerator = Py - Ay - w1 * (By - Ay);
// 	std::cout << "w2 numerator: " << w2_numerator << std::endl;
//     Fixed w2_denominator = Cy - Ay;
// 	std::cout << "w2 numerator: " << w2_numerator << std::endl;
//     Fixed w2 = w2_numerator / w2_denominator;

// 	Fixed r(3);
// 	Fixed s(4);
// 	std::cout << YELLOW << "r: " << r << RESET << std::endl;
// 	std::cout << YELLOW << "s: " << s << RESET << std::endl;
// 	Fixed v_sum = r / s;
// 	std::cout << YELLOW << "v_sum: " << v_sum << RESET << std::endl;

//     Fixed zero(0.0f);
//     Fixed one(1.0f);

//     if (w1 > zero && w2 > zero && (w1 + w2) < one)
//         return (true);
//     return (false);
// }