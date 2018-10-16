#include "Square.h"

Square::Square(double side) : Shape()
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
std::string Square::GetType() const
{
	return "Square";
}
int Square::GetNumSides() const
{
	return 4;
}
double Square::GetSide() const
{
	return m_side;
}
