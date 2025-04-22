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

// is (AB*AP) left (>0) or right (<0) ?
	Fixed	abap = x_ab * y_ap - x_ap * y_ab;
	std::string	resAbap;
	if (abap > 0)
		resAbap = "left";
	else if (abap < 0)
		resAbap = "right";
	else
		resAbap = "middle";

// is (BC*BP) left (>0) or right (<0) ?
	Fixed	bcbp = x_bc * y_bp - x_bp * y_bc;
	std::string	resBcbp;
	if (bcbp > 0)
		resBcbp = "left";
	else if (bcbp < 0)
		resBcbp = "right";
	else
		resBcbp = "middle";

// is (CA*CP) left (>0) or right (<0) ?
	Fixed	cacp = x_ca * y_cp - x_cp * y_ca;
	std::string	resCacp;
	if (cacp > 0)
		resCacp = "left";
	else if (cacp < 0)
		resCacp = "right";
	else
		resCacp = "middle";

// are the 3 results all the same ? then it is inside the triangle
	if (resAbap == resBcbp && resAbap == resCacp)
		return (true);
	return (false);
}

/*

~ THE MATH ~

A->B then B->C then C->D: is P always on the left or always on the right? Then it is inside the triangle.

If P is on the left of AB, it means that BAP is a counter-clock-wise angle.
By mathematical convention, that means (AB * AP) > 0.

if P is on the right of AB, it means that BAP is a clock-wise angle, so (AB * AP) < 0

Vector multiplication:
AB * CD = x_AB * y_CD - x_CD * y_AB

Vector coordinates:
x_AB = x_B - x_A
y_AB = y_B - y_A 

*/
