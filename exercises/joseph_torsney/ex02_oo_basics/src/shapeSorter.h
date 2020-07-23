#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include <vector>
#include "shape.h"

class ShapeSorter {
  public:
    ShapeSorter(std::vector<Shape*> v);
  
    /** Prints the shape objects that match a given type
     * 
     * @param type the type of shapes to print
     */
    void printMatching(std::string type);
    
    /** Prints the shape objects that have a given number of sides
     * 
     * @param sides the number of sides of shapes to print
     */
    void printSides(int sides);

    /** Prints the shapes in descending order by areas
     * 
     */
    void printAreas();

    /** Prints the shapes in descending order of perimeters
     * 
     */
    void printPerimeters();

  private:
    std::vector<Shape*> shapes;

    /** Prints the entire shapes vector
     * 
     */
    void printAll();
};

#endif