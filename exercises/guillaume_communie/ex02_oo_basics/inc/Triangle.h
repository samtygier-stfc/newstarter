#pragma once

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
    double getPerimeter() const override;

    /**
     * Get the area
     * @return The triangle area
     */
    double getArea() const override;

    /**
     * Print the triangle
     * @return A string that contains the triangle data
     */
    std::string print() const override;

private:
    /**
     * Store the triangle height
     */
    double m_height;

    /**
     * Store the triangle base length
     */
    double m_base;
};

