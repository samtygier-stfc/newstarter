#include "Rectangle.h"

Rectangle::Rectangle(double w, double h) : Shape(w * 2 + h * 2, w * h, "Rectangle", 4)
{
	width = w;
	height = h;
}
double Rectangle::GetWidth()
{
	return width;
}
double Rectangle::GetHeight()
{
	return height;
}