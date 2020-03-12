#pragma once

#include "Shape.h"

/**
 * A square
 */
class Square : public Shape {
public:
    /**
     * Create a square by giving its side lenght
     * @param[in] s The square side length
     */
    Square(double s);

    /**
     * Get the perimeter
     * @return The square perimeter
     */
    double getPerimeter() const override;

    /**
     * Get the area
     * @return The square area
     */
    double getArea() const override;

    /**
     * Print the square
     * @return A string that contains the square data
     */
    std::string print() const override;

private:
    /**
     * Store the square side length
     */
    double m_size;
};

