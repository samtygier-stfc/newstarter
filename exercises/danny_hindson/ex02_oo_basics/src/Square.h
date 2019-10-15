// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#ifndef SQUARE_H_
#define SQUARE_H_

#include "Shape.h"

class Square : public Shape {
public:
  double perimeter() const override;
  double area() const override;
  Square(double side) : Shape("Square", 4), side(side) {};
private:
  double side;
};

#endif /* SQUARE_H_*/
