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
        src/Triangle.cpp
        src/Square.cpp
        src/Circle.cpp
        src/ShapeSorter.cpp
        src/Shape.cpp
        src/Rectangle.cpp
        # add any additional source files here
)

set ( HDR_FILES
  # add any additional header files here
        src/Shape.h
        src/Rectangle.h
        src/Triangle.h
        src/Square.h
        src/Circle.h
        src/ShapeSorter.h
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
