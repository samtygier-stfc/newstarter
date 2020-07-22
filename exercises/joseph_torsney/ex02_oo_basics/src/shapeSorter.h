#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include "shape.h"
#include <vector>

class ShapeSorter {
  public:
    ShapeSorter(std::vector<Shape*> v) {
      shapes = v;
    }
  
  /** Prints the shape objects that match a given type
   * 
   * @param type the type of shapes to print
   */
  void printMatching(std::string type) {
    
  }

  /** Prints the shape objects that have a given number of sides
   * 
   * @param sides the number of sides of shapes to print
   */
  void printSides(int sides) {

  }

  /** Prints the areas of the shapes in descending order
   * 
   */
  void printAreas() {

  }

  /** Prints the perimeters of the shapes in descending order
   * 
   */
  void printPerimeters() {

  }

  private:
    std::vector<Shape*> shapes;
};

#endif