#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include "shape.h"
#include <iostream>
#include <vector>
#include <algorithm>

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
      for (auto it = shapes.begin(); it != shapes.end(); it++) {
        if (type == (*it)->getType()) {
          std::cout << (*it)->toString() << std::endl;
        }
      }
    }

    /** Prints the shape objects that have a given number of sides
     * 
     * @param sides the number of sides of shapes to print
     */
    void printSides(int sides) {
      for (auto it = shapes.begin(); it != shapes.end(); it++) {
        if (sides == (*it)->getSides()) {
          std::cout << (*it)->toString() << std::endl;
        }
      }
    }

    /** Prints the shapes in descending order by areas
     * 
     */
    void printAreas() {
      std::sort(shapes.begin(), shapes.end(), 
        [](const auto& a, const auto& b) -> bool {
          return a->getArea() > b->getArea();
        }
      );
      printAll();
    }

    /** Prints the shapes in descending order of perimeters
     * 
     */
    void printPerimeters() {
      std::sort(shapes.begin(), shapes.end(), 
        [](const auto& a, const auto& b) -> bool {
          return a->getPerimeter() > b->getPerimeter();
        }
      );
      printAll();
    }

  private:
    std::vector<Shape*> shapes;

    /** Prints the entire shapes vector
     * 
     */
    void printAll() {
      for (auto it = shapes.begin(); it != shapes.end(); it++) {
        std::cout << (*it)->toString() << std::endl;
      }
    }
};

#endif