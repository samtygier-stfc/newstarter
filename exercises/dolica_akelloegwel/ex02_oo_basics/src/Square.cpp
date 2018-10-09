#include "Square.h"

Square::Square(double s) : Shape(s * 4, s * s, "Square", 4, "This is a square.")
{
	side = s;
}
double Square::GetSide() const
{
	return side;
}