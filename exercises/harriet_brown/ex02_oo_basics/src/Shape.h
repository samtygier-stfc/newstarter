#pragma once
#include <string>
#include <vector>
#include <math.h>

class Shape
{
	private:
		std::string shape;
		double height;
		double width;
	public:
		Shape();
		void setShape(std::string type);
		void setHeight(double side1);
		void setWidth(double side1);
		void setSides(double side1, double side2);
		std::string getShape();
		double getHeight();
		double getWidth();
		std::vector<double> getSides();
		double Shape::getPerimeter();
};