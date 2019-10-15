// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#include "Shape.h"

/**
 * gets the type of shape as a string eg Circle
  */
std::string Shape::getShapeType() const
{
  return ShapeType;
}

/**
 * Calculates number of sides of the shape
  */
int Shape::getShapeSides() const
{
  return nsides;
}

/**
 * Returns description of the shape as a string
  */
std::string Shape::getShapeDetails() const {
  return "Shape Type=" + ShapeType + ", NSides=" + std::to_string(nsides) + ", Area=" + std::to_string(area()) + ", Perimeter=" + std::to_string(perimeter());
}

