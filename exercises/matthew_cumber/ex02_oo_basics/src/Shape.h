#pragma once

#include <string>

/*
 * Abstract class for all shapes for common members and methods
 * m_type : The type of shape determined by derived class
 * m_numSides : The number of sides the shape has determined by derived class
 */
class Shape
{
public:
  virtual ~Shape() = default;

  /// methods to be implemented in derived classes
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual std::string toString() const = 0;

  /// Getters for all shapes
  inline std::string getType() const { return m_type; }
  inline int getNumSides() const { return m_numSides; }

protected:
  std::string m_type;
  int m_numSides;
};