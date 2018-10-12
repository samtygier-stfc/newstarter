cmake_minimum_required ( VERSION 2.8.5 )

find_package(Boost REQUIRED COMPONENTS regex)
include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory ( ex01_basics )
add_subdirectory ( ex02_oo_basics )
