#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Point const	pointA;
	Point const	pointB( 2, 2 );
	Point const	pointC( -2.0f, 2.0f );
	Point const	pointD( 10, -3 );
	Point const	pointE( pointD );

	// Triangle's corners a,b,c:
	Point const	a( -4, 4 );
	Point const	b( -2, -4 );
	Point const	c( 6, -2 );

	{	//pointA:
		if (bsp( a, b, c, pointA ))
			std::cout << LIGHT_GREEN << "Point A is within the triangle" << RESET << std::endl;
		else
			std::cout << BOLD_RED << "Point A is not within the triangle" << RESET << std::endl;
	}
	{	//pointB:
		if (bsp( a, b, c, pointB ))
			std::cout << LIGHT_GREEN << "Point B is within the triangle" << RESET << std::endl;
		else
			std::cout << BOLD_RED << "Point B is not within the triangle" << RESET << std::endl;
	}
	{	//pointC:
		if (bsp( a, b, c, pointC ))
			std::cout << LIGHT_GREEN << "Point C is within the triangle" << RESET << std::endl;
		else
			std::cout << BOLD_RED << "Point C is not within the triangle" << RESET << std::endl;
	}
	{	//pointD:
		if (bsp( a, b, c, pointD ))
			std::cout << LIGHT_GREEN << "Point D is within the triangle" << RESET << std::endl;
		else
			std::cout << BOLD_RED << "Point D is not within the triangle" << RESET << std::endl;
	}
	{	//pointE:
		if (bsp( a, b, c, pointE ))
			std::cout << LIGHT_GREEN << "Point E is within the triangle" << RESET << std::endl;
		else
			std::cout << BOLD_RED << "Point E is not within the triangle" << RESET << std::endl;
	}

	return (0);
}
