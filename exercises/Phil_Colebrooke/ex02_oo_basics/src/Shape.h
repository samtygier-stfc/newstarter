#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
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
  virtual double getPerimeter() const = 0;
  virtual double getArea() const = 0;

  /// Returns the type of shape
  std::string getType() const { return m_type; }

  /// Returns the number of sides the shape has
  int getSides() const { return m_sidesNumber; }

  void printInfo() const;
};

#endif // SHAPE_H
