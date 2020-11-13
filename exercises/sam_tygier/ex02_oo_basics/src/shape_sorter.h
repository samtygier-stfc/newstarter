#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include <ostream>
#include <memory>
#include <vector>

#include "shape.h"

typedef std::vector<std::unique_ptr<Shape>> shapevec;

class ShapeSorter{
public:
	ShapeSorter(const shapevec & shapes): m_shapes(shapes) {}
	void PrintShapesByType(std::ostream &os, const std::string shape_type) const;
	void PrintShapesBySides(std::ostream &os, double shape_sides) const;
	void PrintShapesByArea(std::ostream &os) const;
	void PrintShapesByPerimeter(std::ostream &os) const;
private:
	const shapevec & m_shapes;
};


#endif
