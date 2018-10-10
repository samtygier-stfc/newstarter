#include "Rectangle.h"

Rectangle::Rectangle(double w, double h) : Shape("Rectangle", 4)
{
	// Set width and height information
	m_width = w;
	m_height = h;

	// Set perimeter value
	double perim = w * 2 + h * 2;
	SetPerimeter(perim);

	// Set area value
	double ar = w * h;
	SetArea(ar);

	// Construct and set the message that will be displayed when the object is printed
	std::string rectMessage = "Rectangle Properties: \n";
	rectMessage += "  Width: " + std::to_string(w) + "\n";
	rectMessage += "  Height: " + std::to_string(h);
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