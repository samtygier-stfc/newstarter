#include "Rectangle.h"

Rectangle::Rectangle(double width, double height) : Shape()
{
	// Set width and height information
	m_width = width;
	m_height = height;

	// Construct and set the message that will be displayed when the object is printed
	std::string rectMessage = "Rectangle Properties: \n";
	rectMessage += "  Width: " + std::to_string(width) + "\n";
	rectMessage += "  Height: " + std::to_string(height);
	rectMessage += CreateBaseMessage();

	SetMessage(rectMessage);
}
double Rectangle::GetPerimeter() const
{
	return m_width * 2 + m_height * 2;
}
double Rectangle::GetArea() const
{
	return m_width * m_height;
}
std::string Rectangle::GetType() const
{
	return "Rectangle";
}
int Rectangle::GetNumSides() const
{
	return 4;
}
double Rectangle::GetWidth() const
{
	return m_width;
}
double Rectangle::GetHeight() const
{
	return m_height;
}
