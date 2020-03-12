#pragma once

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
    static void printMatchType(const std::vector<Shape*> &v,
                               const std::string &t);

    /**
     * Print shape that match a certain number of sides
     * @param[in] v The vector of shapes
     * @param[in] n The number of sides to match
     */
    static void printMatchSides(const std::vector<Shape*> &v, int n);

    /**
     * Print the shapes sorted by descending perimeter value
     * @param[in] v The vector of shapes
     */
    static void printSortedByPerimeter(std::vector<Shape*> v);

    /**
     * Print the shapes sorted by descending area value
     * @param[in] v The vector of shapes
     */
    static void printSortedByArea(std::vector<Shape*> v);

private:
    /**
     * Print a verctor on std::cout
     * @param[in] v The vector
     */
    static void printVector(const std::vector<Shape*> &v);
};

