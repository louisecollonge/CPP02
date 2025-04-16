#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	// coordinates for vectors ab, bc, ca:
	Fixed	x_ab = b.getx() - a.getx();
	Fixed	y_ab = b.gety() - a.gety();
	Fixed	x_bc = c.getx() - b.getx();
	Fixed	y_bc = c.gety() - b.gety();
	Fixed	x_ca = a.getx() - c.getx();
	Fixed	y_ca = a.gety() - c.gety();

	//coordinates for vectors ap, bp and cp:
	Fixed	x_ap = point.getx() - a.getx();
	Fixed	y_ap = point.gety() - a.gety();
	Fixed	x_bp = point.getx() - b.getx();
	Fixed	y_bp = point.gety() - b.gety();
	Fixed	x_cp = point.getx() - c.getx();
	Fixed	y_cp = point.gety() - c.gety();

// is ab * P left (>0) or right (<0) ?
	Fixed	abap = x_ab * y_ap - x_ap * y_ab;
	std::string	resAbap;
	if (abap > 0)
		resAbap = "left";
	else if (abap < 0)
		resAbap = "right";
	else
		resAbap = "middle";

// is bc * P left (>0) or right (<0) ?
	Fixed	bcap = x_bc * y_bp - x_bp * y_bc;
	std::string	resBcap;
	if (bcap > 0)
		resBcap = "left";
	else if (bcap < 0)
		resBcap = "right";
	else
		resBcap = "middle";

// is cd * P left (>0) or right (<0) ?
	Fixed	caap = x_ca * y_cp - x_cp * y_ca;
	std::string	resCaap;
	if (caap > 0)
		resCaap = "left";
	else if (caap < 0)
		resCaap = "right";
	else
		resCaap = "middle";

// are the 3 results all the same ? then it is inside the triangle
	if (resAbap == resBcap && resAbap == resCaap)
		return (true);
	return (false);
}

// A->B then B->C then C->D: 
// is P always on the left or always on the right?
// then it is inside the triangle.

// if P is on the left of AB, it means that:
// A->B->P is a counter-clock-wise angle
// by mathematical convention, that means:
// AB * AP > 0

// if P is on the right of AB, it means that:
// A->B->P is a clock-wise angle
// that means: AB * AP < 0

// vector multiplication:
// AB * CD = x_AB * y_CD - x_CD * y_AB

// vector coordinates:
// x_AB = x_B - x_A
// y_AB = y_B - y_A
