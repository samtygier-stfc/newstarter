#include "Square.h"

Square::Square(double side) : Shape("Square", 4)
{
	// Set the side value
	m_side = side;

	// Construct and set a message used for overloading <<
	std::string squareMessage = "Square Properties:\n";
	squareMessage += "  Side: " + std::to_string(side);
	squareMessage += CreateBaseMessage();

	SetMessage(squareMessage);
}
double Square::GetPerimeter() const
{
	return m_side * 4;
}
double Square::GetArea() const
{
	return m_side * m_side;
}
double Square::GetSide() const
{
	return m_side;
}
