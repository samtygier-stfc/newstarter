#pragma once

#include "Shape.h"

/**
 * A retangle
 */
class Rectangle : public Shape {
public:
    /**
     * Create a rectangle by providing its height and width
     * @param[in] h The reclangle height
     * @param[in] w The rectangle width
     */
    Rectangle(double h, double w);

    /**
     * Get the perimeter
     * @return The rectangle perimeter
     */
    double getPerimeter() const override;

    /**
     * Get the area
     * @return The rectangle area
     */
    double getArea() const override;

    /**
     * Print the rectangle
     * @return A string that contains rectangle data
     */
    std::string print() const override;

private:
    /**
     * Store the rectangle height
     */
    double m_height;

    /**
     * Store the rectangle width
     */
    double m_width;
};

