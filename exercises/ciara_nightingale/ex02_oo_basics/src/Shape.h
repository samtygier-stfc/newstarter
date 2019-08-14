#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape {
public:
  /// Constructor to give the shape a type and the number of sides.
  Shape(std::string type, int sides);
  /// Initialise the perimeter and area functions.
  virtual double perimeter() const = 0;
  virtual double area() const = 0;
  /// Function to provide read only acess to the type and number of sides
  /// variables.
  std::string getType() const;
  int getSides() const;

private:
  std::string const m_type;
  int const m_sides;
};
#endif // SHAPE_H
