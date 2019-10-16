// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#include "Triangle.h"
#include <math.h>

/**
 * Calculates perimeter of the triangle
  */
double Triangle::perimeter() const {
  return 0.5 * m_height * m_base;
}

/**
 * Calculates perimeter of the triangle
  */
double Triangle::area() const {
  return m_base + 2 * sqrt(pow(m_height, 2) + (pow(m_base, 2) / 4));
}