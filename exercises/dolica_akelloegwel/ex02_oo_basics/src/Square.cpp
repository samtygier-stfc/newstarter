#include "Square.h"

Square::Square(double s) : Shape(s * 4, s * s, "Square", 4)
{
	side = s;
}
