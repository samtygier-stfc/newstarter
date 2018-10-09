#include "Square.h"

Square::Square(double s) : Shape(s * 4, s * s, "Square", 4)
{
	side = s;
}
double Square::GetSide() const
{
	return side;
}
void Square::write(std::ostream & os) const
{
	os << "This is a square." << std::endl;
}