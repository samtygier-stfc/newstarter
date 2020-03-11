#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

/**
 * A triangle
 */
class Triangle : public Shape {
public:
    /**
     * Create a triangle by providing its height and base length
     * @param[in] h The triangle height
     * @param[in] b The triangle base length
     */
    Triangle(double h, double b);

    /**
     * Get the perimeter
     * @return The triangle perimeter
     */
    double getPerimeter(void);

    /**
     * Get the area
     * @return The triangle area
     */
    double getArea(void);

private:
    /**
     * Store the triangle height
     */
    double height;

    /**
     * Store the triangle base length
     */
    double base;
};

#endif

