#include "Square.h"

Square::Square(double s) : Shape("Square", 4)
{
	side = s;

	SetPerimeter(s * 4);
	SetArea(s * s);
	SetMessage("This is a square.");
}
double Square::GetSide() const
{
	return side;
}