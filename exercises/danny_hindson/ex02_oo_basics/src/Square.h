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
  Square(double side) : Shape("Square", 4), m_side(side) {};
  double perimeter() const override;
  double area() const override;
private:
  double m_side;
};

#endif /* SQUARE_H_*/
