#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "ShapeSorter.h"
#include <vector>

int main() {
		std:vector<> shapes;
		ShapeSorter(shapes) sorted;
		sorted.printType();
		sorted.printSide();
		sorted.printPerimeterDescending();
		sorted.printAreaDescending();
		return 0;
}