#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Shape
{
protected:
	string type;
	int sides;
public:
	void print();
	string get_type();
	int get_sides();
	virtual double area() = 0;
	virtual double perimeter() = 0;
	Shape(string type, int sides);
};

Shape::Shape(string type, int sides)
{
	Shape::type = type;
	Shape::sides = sides;
}

void Shape::print()
{
	cout << "Type = " << get_type() << ", Sides = " << get_sides() 
		<< ", Area = " << area() << ", Perimeter = " << perimeter() << endl;
}

string Shape::get_type()
{
	return type;
}

int Shape::get_sides()
{
	return sides;
}

typedef vector<Shape*>::const_iterator shape_iter;

class Rectangle : public Shape
{
protected:
	double side1;
	double side2;
public:
	double area();
	double perimeter();
	Rectangle(double side1, double side2);
};

Rectangle::Rectangle(double side1, double side2) : Shape("rectangle", 4)
{
	Rectangle::side1 = side1;
	Rectangle::side2 = side2;
}

double Rectangle::area()
{
	return side1 * side2;
}

double Rectangle::perimeter()
{
	return 2 * (side1 + side2);
}

class Square : public Rectangle
{
public:
	Square(double side1);
};

Square::Square(double side1) : Rectangle(side1, side1)
{
	type = "square";
}

class Triangle : public Shape
{
protected:
	double base;
	double height;
public:
	double area();
	double perimeter();
	Triangle(double base, double height);
};

Triangle::Triangle(double base, double height) : Shape("triangle", 3)
{
	Triangle::base = base;
	Triangle::height = height;
}

double Triangle::area()
{
	return (base * height) / 2;
}

double Triangle::perimeter()
{
	return base + 2 * sqrt(pow(height, 2) + (pow(base, 2) / 4));
}

class Circle : public Shape
{
protected:
	double radius;
public:
	double area();
	double perimeter();
	Circle(double radius);
};

Circle::Circle(double radius) : Shape("circle", 0)
{
	Circle::radius = radius;
}

double Circle::area()
{
	return M_PI * pow(radius, 2);
}

double Circle::perimeter()
{
	return 2 * M_PI * radius;
}

struct ShapeSorter
{
	static void matches_type(vector<Shape*> shapes, string type);
	static void matches_sides(vector<Shape*> shapes, int sides);
	static void area_desc(vector<Shape*> shapes);
	static void perimeter_desc(vector<Shape*> shapes);
};

void ShapeSorter::matches_type(vector<Shape*> shapes, string type)
{
	cout << "Shapes matching type \"" << type << "\"..." << endl;

	int i = 1;
	for (shape_iter it = shapes.begin(); it != shapes.end(); it++)
	{
		if ((*it)->get_type() == type)
		{
			cout << "Shape " << i << " --- ";
			(*it)->print();
			i++;
		}
	}
	cout << endl;
}

void ShapeSorter::matches_sides(vector<Shape*> shapes, int sides)
{
	cout << "Shapes matching " << sides << " sides..." << endl;

	int i = 1;
	for (shape_iter it = shapes.begin(); it != shapes.end(); it++)
	{
		if ((*it)->get_sides() == sides)
		{
			cout << "Shape " << i << " --- ";
			(*it)->print();
			i++;
		}
	}
	cout << endl;
}

void ShapeSorter::area_desc(vector<Shape*> shapes) {}
void ShapeSorter::perimeter_desc(vector<Shape*> shapes) {}

int main()
{
	// create a vector of several shapes
	vector<Shape*> shapes;
	shapes.push_back(new Rectangle(5, 10));
	shapes.push_back(new Square(3));
	shapes.push_back(new Triangle(4, 7));
	shapes.push_back(new Circle(5));

	// call several ShapeSorter functions on the shapes
	ShapeSorter::matches_type(shapes, "circle");
	ShapeSorter::matches_sides(shapes, 4);

	return 0;
}
