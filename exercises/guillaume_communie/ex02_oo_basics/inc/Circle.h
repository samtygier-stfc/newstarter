#pragma once

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
    double getPerimeter() const override;

    /**
     * Get the area
     * @return The circle area
     */
    double getArea() const override;

    /**
     * Print the circle
     * @return A string that contains the circle data
     */
    std::string print() const override;

private:
    /**
     * Store the circle radius
     */
    double m_radius;
};

