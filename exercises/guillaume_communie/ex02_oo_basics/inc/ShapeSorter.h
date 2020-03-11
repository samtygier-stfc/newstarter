#ifndef SHAPE_SORTER_H
#define SHAPE_SORTER_H

#include "Shape.h"

#include <vector>
#include <string>

/**
 * A shape sorter
 */
class ShapeSorter {
public:
    /**
     * Print shape that match a certain type
     * @param[in] v The vector of shapes
     * @param[in] t The type to match
     */
    static void printMatchType(std::vector<Shape*> v, std::string t);

    /**
     * Print shape that match a certain number of sides
     * @param[in] v The vector of shapes
     * @param[in] n The number of sides to match
     */
    static void printMatchSides(std::vector<Shape*> v, int n);

    /**
     * Print the shapes sorted by descending perimeter value. The methods first
     * modifies the vector by sorting its elements
     * @param[in,out] v The vector of shapes
     */
    static void printSortedByPerimeter(std::vector<Shape*> v);

    /**
     * Print the shapes sorted by descending area value. The methods first
     * modifies the vector by sorting its elements
     * @param[in,out] v The vector of shapes
     */
    static void printSortedByArea(std::vector<Shape*> v);
};

#endif

