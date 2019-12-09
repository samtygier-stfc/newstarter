cmake_minimum_required ( VERSION 2.8.5 )

###############################################################################
# Setup
###############################################################################
# Name
project ( Shapes )

# Find custom cmake modules
set ( CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../CMake")

# Common setup
include ( CommonSetup )

###############################################################################
# Executable
###############################################################################

set ( SRC_FILES
  src/main.cpp
  src/triangle.cpp
  src/square.cpp
  src/rectangle.cpp
  src/circle.cpp
  src/shapesorter.cpp
  src/shape.cpp
  # add any additional source files here
)

set ( HDR_FILES
  # add any additional header files here
  src/shape.h
  src/triangle.h
  src/square.h
  src/rectangle.h
  src/circle.cpp
  src/shapesorter.h
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
