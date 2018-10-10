#include "Square.h"

Square::Square(double side) : Shape("Square", 4)
{
	// Set the side value
	m_side = side;

	// Compute and set the perimeter value
	double perim = side * 4;
	SetPerimeter(perim);

	// Compute and set the area value
	double area = side * side;
	SetArea(side * side);

	// Construct and set a message used for overloading <<
	std::string squareMessage = "Square Properties:\n";
	squareMessage += "  Side: " + std::to_string(side);
	squareMessage += CreateBaseMessage();

	SetMessage(squareMessage);
}
double Square::GetSide() const
{
	return m_side;
}