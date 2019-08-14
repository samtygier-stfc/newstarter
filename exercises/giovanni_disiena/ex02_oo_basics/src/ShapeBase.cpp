#include "ShapeBase.h"

/** Constructs ShapeBase object
 *
 * @param numberOfSides: number of sides of the shape
 * @param name: name of shape type
 *
 */
ShapeBase::ShapeBase(unsigned int numberOfSides, std::string name)
    : m_numberOfSides(numberOfSides), m_name(name){};

/** Retrieves shape type name member variable
 *
 * @return m_name: name member variable
 *
 */
std::string ShapeBase::getName() const { return m_name; }

/** Retrieves shape number of sides member variable
 *
 * @return m_numberOfSides: number of sides member variable
 *
 */
unsigned ShapeBase::getNumberOfSides() const { return m_numberOfSides; }