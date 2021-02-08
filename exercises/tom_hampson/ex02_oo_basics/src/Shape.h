#pragma once

#include <string>
/**
 * @brief Base class for shapes. We store the area and perimeter rather than calculate it on the fly
 * because it's more efficient.
*/
class Shape
{
public:
  //Forbid use of default construtor so that shape is always completely configured.
  Shape() = delete;
  Shape(const int nSides, const std::string& shapeType);
  virtual ~Shape() {};

  virtual void print() const;

protected:
  virtual void calculateArea() = 0;
  virtual void calculatePerimeter() = 0;
  double m_area;
  double m_perimeter;

private:
  double m_nSides;

  std::string m_shapeType;
};

