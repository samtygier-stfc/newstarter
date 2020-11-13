#ifndef Shape_h
#define Shape_h

class Shape
{
public:
	enum class ShapeType { Circle, Triangle, Rectangle, Square };

	Shape(const ShapeType _type)
		: type{ _type }
	{}

	virtual  ~Shape() {};

	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;
	auto getType() const { return type; };
	virtual unsigned int getNumberOfSides() const = 0;

private:
	ShapeType type;
};

#endif