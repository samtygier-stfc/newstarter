###############################################################################
# CommonSetup.cmake
###############################################################################

# We want shared libraries everywhere
set ( BUILD_SHARED_LIBS On )

# Send libraries to common place
set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )
set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )

# This allows us to group targets logically in Visual Studio
set_property ( GLOBAL PROPERTY USE_FOLDERS ON )

set ( CMAKE_CXX_STANDARD 17 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_EXTENSIONS OFF )

# Enable warnings in all subprojects
if(MSVC)
  add_compile_options(/W3 /WX)  # W3 avoids std lib warnings
else()
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()


add_definitions ( -D_USE_MATH_DEFINES )
