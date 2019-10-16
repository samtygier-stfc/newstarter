// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape {
public:
  Rectangle(double side1, double side2) : Shape("Rectangle", 4), m_side1(side1), m_side2(side2) {};
  double perimeter() const override;
  double area() const override;
private:
  double m_side1;
  double m_side2;
};

#endif /* RECTANGLE_H_*/