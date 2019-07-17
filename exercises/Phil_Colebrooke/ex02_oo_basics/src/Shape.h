#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
private:
  const std::string m_type;
  const int m_sidesNumber;

public:
  /// Constructor
  Shape(std::string type, int sidesNumber);

  /// Pure abstract functions
  /// Shape cannot be instansiated
  virtual double getPerimeter() = 0;
  virtual double getArea() = 0;

  /// Returns the type of shape
  std::string getType() { return m_type; }

  /// Returns the number of sides the shape has
  int getSides() { return m_sidesNumber; }
};

#endif // SHAPE_H
