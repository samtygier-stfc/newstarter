cmake_minimum_required ( VERSION 2.8.5 )

###############################################################################
# Setup
###############################################################################
# Name
project ( Shapes )

# Find custom cmake modules
set ( CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../CMake")
set(CONAN "AUTO" CACHE STRING "conan options AUTO (conan must be in path) or MANUAL (expects conanbuildinfo.cmake in build directory)")
set(CONAN_PROFILE "default" CACHE STRING "Name of conan profile to use, uses default by default")
include(${CMAKE_MODULE_PATH}/conan.cmake)
if(${CONAN} MATCHES "AUTO")
    conan_cmake_run(CONANFILE conanfile.txt
            PROFILE ${CONAN_PROFILE}
            BASIC_SETUP CMAKE_TARGETS
            BUILD outdated)
elseif(${CONAN} MATCHES "MANUAL")
    if(EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
        include("${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
        conan_basic_setup(TARGETS)
    else()
        message(FATAL_ERROR "CONAN set to MANUAL but no file named conanbuildinfo.cmake found in build directory")
    endif()
else()
    message(FATAL_ERROR "Unrecognised option for CONAN, use AUTO or MANUAL")
endif()

# Common setup
include ( CommonSetup )

###############################################################################
# Executable
###############################################################################

set ( SRC_FILES
  src/Shape.cpp
  src/Square.cpp
  src/Rectangle.cpp
  src/Triangle.cpp
  src/Circle.cpp
  src/ShapeSorter.cpp
  src/main.cpp
  # add any additional source files here
)

set ( HDR_FILES
  src/Shape.h
  src/Square.h
  src/Rectangle.h
  src/Triangle.h
  src/Circle.h
  src/ShapeSorter.h
 )

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
add_executable(CircleTests src/Shape.h src/Shape.cpp src/Circle.h src/Circle.cpp tests/CircleTests.cpp)
add_executable(RectangleTests src/Shape.h src/Shape.cpp src/Rectangle.h src/Rectangle.cpp tests/RectangleTests.cpp)
add_executable(SquareTests src/Shape.h src/Shape.cpp src/Square.h src/Square.cpp tests/SquareTests.cpp)
add_executable(TriangleTests src/Shape.h src/Shape.cpp src/Triangle.h src/Triangle.cpp tests/TriangleTests.cpp)

target_link_libraries(CircleTests
        CONAN_PKG::gtest)
target_link_libraries(RectangleTests
        CONAN_PKG::gtest)
target_link_libraries(SquareTests
        CONAN_PKG::gtest)
target_link_libraries(TriangleTests
        CONAN_PKG::gtest)
