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
		src/Circle.cpp
		src/Rectangle.cpp
		src/ShapeSorter.cpp
		src/Shape.cpp
		src/Square.cpp
)

set ( HDR_FILES
		src/Triangle.h
		src/Circle.h
		src/Rectangle.h
		src/ShapeSorter.h
		src/Shape.h
		src/Square.h
)
message(STATUS ${HDR_FILES})
message(STATUS ${SRC_FILES})
add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
