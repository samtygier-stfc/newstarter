// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

class Shape {
public:
  Shape(std::string ShapeType, int nsides) : ShapeType(ShapeType), nsides(nsides) {};
  virtual ~Shape() = default;
  std::string getShapeType() const;
  int getShapeSides() const;
  virtual std::string getShapeDetails() const;
  virtual double perimeter() const = 0 ;
  virtual double area() const = 0 ;
private:
  std::string ShapeType;
  int nsides;
};

#endif /* SHAPE_H_*/
