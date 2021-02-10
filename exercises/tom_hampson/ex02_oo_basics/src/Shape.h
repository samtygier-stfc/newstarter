#pragma once

#include <string>
/**
 * @brief Base class for shapes. We calculate the area and perimeter at time of
 * object creation rather than calculate it on the fly because it's more efficient.
*/
class Shape
{
public:
  //Forbid use of default construtor so that shape is always completely configured.
  Shape() = delete;
  Shape(const int nSides, const std::string& shapeType);
  virtual ~Shape() {};

  virtual void print() const;

  const std::string& shapeType() const;
  int nSides() const;
  double area() const;
  double perimeter() const;

private:
  std::string m_shapeType;
  int m_nSides;

protected:
  //Call these functions inside derived class constructors to set the
  //values for area and perimeter so we don't have to calculate them
  //on the fly.
  virtual void calculateArea() = 0;
  virtual void calculatePerimeter() = 0;
  double m_area;
  double m_perimeter;
};

