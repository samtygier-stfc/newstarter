// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#include "Rectangle.h"

/**
 * Calculates perimeter of the rectangle
  */
double Rectangle::perimeter() const {
  return 2 * side1 + 2 * side2;
}

/**
 * Calculates perimeter of the rectangle
  */
double Rectangle::area() const {
  return side1 * side2;
}