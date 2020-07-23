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
  src/shapeSorter.cpp
  src/square.cpp
  src/triangle.cpp
  src/circle.cpp
  src/rect.cpp
  src/shape.cpp
  src/main.cpp
  # add any additional source files here
)

set ( HDR_FILES
  src/shapeSorter.h
  src/square.h
  src/triangle.h
  src/circle.h
  src/rect.h
  src/shape.h
  # add any additional header files here
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
