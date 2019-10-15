// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"

class Circle : public Shape {
public:
  double perimeter() const override;
  double area() const override;
  Circle(double radius) : Shape("Circle", 1), radius(radius) {};
private:
  double radius;
};

#endif /* CIRCLE_H_*/