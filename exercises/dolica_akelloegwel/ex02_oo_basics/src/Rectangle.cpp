#include "Rectangle.h"

Rectangle::Rectangle(double w, double h) : Shape("Rectangle", 4)
{
	width = w;
	height = h;

	SetPerimeter(w * 2 + h * 2);
	SetArea(w * h);
	SetMessage("This is a rectangle.");
}
double Rectangle::GetWidth()
{
	return width;
}
double Rectangle::GetHeight()
{
	return height;
}

/**
std::ostream & Rectangle::operator<<(std::ostream & os)
{
	return os << " is a " << this->GetType() << " with height " << this->GetHeight() << " and width " << this->GetWidth() << "." << std::endl;
}
**/