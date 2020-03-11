#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

/**
 * A circle
 */
class Circle : public Shape {
public:
    /**
     * Create a circle by providing its radius
     * @param[in] r The circle radius
     */
    Circle(double r);

    /**
     * Get the perimeter
     * @return The circle perimeter
     */
    double getPerimeter(void);

    /**
     * Get the area
     * @return The circle area
     */
    double getArea(void);

    /**
     * Print the circle
     * @return A string that contains the circle data
     */
    std::string print(void);

private:
    /**
     * Store the circle radius
     */
    double radius;
};

#endif

