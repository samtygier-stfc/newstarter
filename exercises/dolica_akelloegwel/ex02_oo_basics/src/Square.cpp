#include "Square.h"

Square::Square(double s) : Shape(s * 4, s * s, "Square", 4)
{
	side = s;
}
double Square::GetSide()
{
	return side;
}
void Square::write(std::ostream & os) const
{
	os << "This is a square." << std::endl;
}
/**
std::ostream& Square::operator<<(std::ostream& os)
{
	return os << " is a " << this->GetType() << " with sides of length " << this->side << "." << std::endl;
}
**/