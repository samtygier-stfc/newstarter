#include "Rectangle.h"

Rectangle::Rectangle(double weight, double height) : Shape("Rectangle", 4)
{
	// Set width and height information
	m_width = weight;
	m_height = height;

	// Set perimeter value
	double perim = weight * 2 + height * 2;
	SetPerimeter(perim);

	// Set area value
	double ar = weight * height;
	SetArea(ar);

	// Construct and set the message that will be displayed when the object is printed
	std::string rectMessage = "Rectangle Properties: \n";
	rectMessage += "  Width: " + std::to_string(weight) + "\n";
	rectMessage += "  Height: " + std::to_string(height);
	rectMessage += CreateBaseMessage();

	SetMessage(rectMessage);
}
double Rectangle::GetWidth()
{
	return m_width;
}
double Rectangle::GetHeight()
{
	return m_height;
}