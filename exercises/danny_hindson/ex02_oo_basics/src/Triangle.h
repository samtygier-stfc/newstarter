// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle : public Shape {
public:
  double perimeter() const override;
  double area() const override;
  Triangle(double height, double base) : Shape("Triangle", 3), height(height), base(base) {};
private:
  double height, base;
};

#endif /* TRIANGLE_H_*/
