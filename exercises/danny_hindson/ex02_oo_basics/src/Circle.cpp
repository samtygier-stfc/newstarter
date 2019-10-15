// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#include "Circle.h"
#include <math.h>

/**
 * Calculates perimeter of the circle
  */
double Circle::perimeter() const {
  return 2 * M_PI * radius;
}

/**
 * Calculates area of the circle
  */
double Circle::area() const {
  return M_PI * pow(radius, 2);
}