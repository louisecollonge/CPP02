#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point( const float a, const float b ) : x(a), y(b) {}

Point::Point( const Point& other ) : x(other.x), y(other.y) {}

Point::~Point() {}

Point	&Point::operator=( const Point& alternative )	// This operator doesn't do anything. It cannot work bc x and y are const...
														// We cannot instanciate a new Point object and return it
														// because the = is supposed to modify the current object *this, NOT replace it. 
														// Plus that would mean returning a local object through its reference, and that is undefined
														// and dangerous since it is supposed to be destroyed at the end of the function.
{
	(void)alternative;
	return (*this); 	
}

const Fixed	Point::getx() const { return (x); }

const Fixed	Point::gety() const { return (y); }
