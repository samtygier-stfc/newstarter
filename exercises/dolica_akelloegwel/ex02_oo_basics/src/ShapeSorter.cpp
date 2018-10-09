#include "ShapeSorter.h"

void ShapeSorter::PrintType(std::vector<Shape> shapes, std::string type)
{
	int i = 0;

	for (std::vector<Shape>::iterator it = shapes.begin(); it != shapes.end(); it++, i++) {

		if (it->GetType().compare(type) == 0)
			std::cout << *it << std::endl;
	}
}
