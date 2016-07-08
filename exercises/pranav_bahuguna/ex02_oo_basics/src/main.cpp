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
	virtual double area() = 0;
	virtual double perimeter() = 0;
};

class Rectangle : public Shape
{
protected:
	double side1;
	double side2;
public:
	double area();
	double perimeter();
	Rectangle();
	Rectangle(double side1, double side2);
};

Rectangle::Rectangle()
{
	type = "rectangle";
	sides = 4;
}

Rectangle::Rectangle(double side1, double side2)
{
	Rectangle();
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
	Square();
	Square(double side1);
};

Square::Square()
{
	type = "square";
	sides = 4;
}

Square::Square(double side1)
{
	Rectangle(side1, side1);
	Square();
}

class Triangle : public Shape
{
protected:
	double base;
	double height;
public:
	double area();
	double perimeter();
	Triangle();
	Triangle(double base, double height);
};

Triangle::Triangle()
{
	type = "triangle";
	sides = 3;
}

Triangle::Triangle(double base, double height)
{
	Triangle();
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
	Circle();
	Circle(double radius);
};

Circle::Circle()
{
	type = "circle";
	sides = INFINITY;
}

Circle::Circle(double radius)
{
	Circle();
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
	vector<Shape*> matches_type(vector<Shape*> shapes, string type);
	vector<Shape*> matches_sides(vector<Shape*> shapes, int sides);
	vector<Shape*> area_desc(vector<Shape*> shapes);
	vector<Shape*> perimeter_desc(vector<Shape*> shapes);
};

vector<Shape*> ShapeSorter::matches_type(vector<Shape*> shapes, string type) {}
vector<Shape*> ShapeSorter::matches_sides(vector<Shape*> shapes, int sides) {}
vector<Shape*> ShapeSorter::area_desc(vector<Shape*> shapes) {}
vector<Shape*> ShapeSorter::perimeter_desc(vector<Shape*> shapes) {}

int main()
{
	// create a vector of several shapes
	vector<Shape*> shapes;
	shapes.push_back(new Rectangle(5, 10));
	shapes.push_back(new Square(3));
	shapes.push_back(new Triangle(4, 7));
	shapes.push_back(new Circle(5));

	return 0;
}
