#include "Square.h"

Square::Square(double s)
{
	side = s;
}
double Square::GetPerimiter()
{
	double side * 4;
}
double Square::GetArea()
{
	return side * side;
}