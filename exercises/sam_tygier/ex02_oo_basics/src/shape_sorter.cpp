#include <algorithm>
#include <utility>

#include "shape_sorter.h"

void ShapeSorter::PrintShapesByType(std::ostream &os, const std::string shape_type) const {
	for(auto &s: m_shapes)
	{
		if(s->getType() == shape_type)
			os << *s << std::endl;
	}
}

void ShapeSorter::PrintShapesBySides(std::ostream &os, double shape_sides) const {
	for(auto &s: m_shapes)
	{
		if(s->getSides() == shape_sides)
			os << *s << std::endl;
	}
}

void ShapeSorter::PrintShapesByArea(std::ostream &os) const {
	// use sortable vector with none owning bare pointers
	std::vector<std::pair<double, Shape*>> shape_areas;
	for(auto &s: m_shapes){
		shape_areas.push_back({s->getArea(), s.get()});
	}

	std::sort(shape_areas.begin(), shape_areas.end(),
	[](auto &leftShape, auto &rightShape){return leftShape.first > rightShape.first;});

	for(auto &s: shape_areas){
		os << *(s.second) << std::endl;
	}
}

void ShapeSorter::PrintShapesByPerimeter(std::ostream &os) const {
	std::vector<std::pair<double, Shape*>> shape_perimeter;
	for(auto &s: m_shapes){
		shape_perimeter.push_back({s->getPerimeter(), s.get()});
	}

	std::sort(shape_perimeter.begin(), shape_perimeter.end(),
	[](auto &leftShape, auto &rightShape){return leftShape.first > rightShape.first;});

	for(auto &s: shape_perimeter){
		os << *(s.second) << std::endl;
	}
}
