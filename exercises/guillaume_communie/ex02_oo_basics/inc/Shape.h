#ifndef SHAPE_H
#define SHAPE_H

#include <string>

/**
 * A shape
 */
class Shape {
public:
    /**
     * Create a shape by a given type name and a number of sides
     * @param[in] t The type name
     * @param[in] n The number of sides
     */
    Shape(std::string t, int n);

    /**
     * Delete a shape
     */
    //~Shape(void);

    /**
     * Get the type name of the shape
     * @return The type name
     */
    std::string getType(void);

    /**
     * Get the number of sides
     * @return The shape number of sides
     */
    int getSides(void);

    /**
     * Get the perimeter
     * @return The shape perimeter
     */
    virtual double getPerimeter(void) = 0;

    /**
     * Get the area
     * @return The shape area
     */
    virtual double getArea(void) =0;

    /**
     * Print the shape
     * @return A string that contains the shape data
     */
    virtual std::string print(void) = 0;

private:
    /**
     * Store the shape type name
     */
    std::string type;

    /**
     * Store the shape number of sides
     */
    int numberOfSides;
};

#endif

