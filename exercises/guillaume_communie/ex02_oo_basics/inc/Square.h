#ifndef SQUARE_H
#define SQUARE_H

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
    double getPerimeter(void);

    /**
     * Get the area
     * @return The square area
     */
    double getArea(void);

private:
    /**
     * Store the square side length
     */
    double size;
};

#endif

