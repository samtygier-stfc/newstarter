// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#include "Triangle.h"

/**
 * Calculates perimeter of the triangle
  */
double Triangle::perimeter() const {
  return 0.5 * height * base;
}

/**
 * Calculates perimeter of the triangle
  */
double Triangle::area() const {
  return base + 2 * sqrt(pow(height, 2) + (pow(base, 2) / 4));
}