#include <vector>
#include "ShapeSorter.h"
#include <iostream>
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "ShapeSorter.h"
#include <algorithm>

ShapeSorter::ShapeSorter() :m_shapes(0) {}

ShapeSorter::ShapeSorter(std::vector<Shape> shapes) :m_shapes(shapes) {}

void ShapeSorter::printType() const {
		for (unsigned i = 0; i != m_shapes.size(); ++i) {
				std::cout << m_shapes[i].getType() << "\n";
		}
}

void ShapeSorter::printSide(int side) const {
		for (unsigned i = 0; i != m_shapes.size(); ++i) {
				if (m_shapes[i].getSides() == side) {
						std::cout << m_shapes[i].getType << m_shapes[i].getSides() << "\n";
				}
		}
}

bool ShapeSorter::compareShapesArea(Shape* shape1, Shape* shape2) const {
		return shape1->area() < shape2->area();
}

bool ShapeSorter::compareShapesPerimeter(Shape* shape1, Shape* shape2) const {
		return shape1->perimeter() < shape2->perimeter();
}

void ShapeSorter::printAreaDescending() const {
		std::cout << "SHAPE AREA" << "\n";
		std::sort(m_shapes.begin(), m_shapes.end(), compareShapesArea);
		for (unsigned i = 0; i != m_shapes.size(); ++i) {
				std::cout << m_shapes[i].getType << m_shapes[i].area() << "\n";
		} 
}

void ShapeSorter::printPerimeterDescending() const {
		std::cout << "SHAPE Perimeter" << "\n";
		std::sort(m_shapes.begin(), m_shapes.end(), compareShapesPerimeter);
		for (unsigned i = 0; i != m_shapes.size(); ++i) {
				std::cout << m_shapes[i].getType << m_shapes[i].perimeter();
		}
}