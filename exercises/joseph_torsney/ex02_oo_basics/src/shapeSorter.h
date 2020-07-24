#pragma once 

#include <vector>
#include <memory>

#include "shape.h"

class ShapeSorter {
  public:
    ShapeSorter(std::vector<std::shared_ptr<Shape>> v);
  
    /** Prints the shape objects that match a given type
     * 
     * @param type the type of shapes to print
     */
    void printMatching(const std::string &type);
    
    /** Prints the shape objects that have a given number of sides
     * 
     * @param sides the number of sides of shapes to print
     */
    void printSides(const int &sides);

    /** Prints the shapes in descending order by areas
     * 
     */
    void printAreas();

    /** Prints the shapes in descending order of perimeters
     * 
     */
    void printPerimeters();

  private:
    const std::vector<std::shared_ptr<Shape>> m_shapes;

    /** Prints the entire shapes vector
     * 
     */
    void printAll();
};
