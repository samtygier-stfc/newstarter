#pragma once

/*
 Abstract class for all shapes for common members and methods
 */
class Shape
{
public:
  virtual ~Shape() = default;

  /// methods to be implemented in derived classes
  virtual float area() = 0;
  virtual float perimeter() = 0;

  /// Getters for all shapes
  inline std::string getType() const { return type; }
  inline int getNumSides() const { return numSides; }

protected:
  std::string type;
  int numSides;
};