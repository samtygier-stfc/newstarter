#include "Square.h"

Square::Square(double s) : Shape("Square", 4)
{
	// Set the side value
	side = s;

	// Compute and set the perimeter value
	double perim = s * 4;
	SetPerimeter(perim);

	// Compute and set the area value
	double area = s * s;
	SetArea(s * s);

	// Construct and set a message used for overloading <<
	std::string squareMessage = "Square Properties:\n";
	squareMessage += " Side: " + std::to_string(s);
	squareMessage += CreateBaseMessage();

	SetMessage(squareMessage);
}
double Square::GetSide() const
{
	return side;
}