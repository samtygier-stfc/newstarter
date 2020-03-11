#ifndef RECTANGLE_H
#define RECTANGLE_H

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
    double getPerimeter(void);

    /**
     * Get the area
     * @return The rectangle area
     */
    double getArea(void);

    /**
     * Print the rectangle
     * @return A string that contains rectangle data
     */
    std::string print(void);

private:
    /**
     * Store the rectangle height
     */
    double height;

    /**
     * Store the rectangle width
     */
    double width;
};

#endif

