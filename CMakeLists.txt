cmake_minimum_required(VERSION 3.14)
project(demo_project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Set compiler flags based on the system
if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_C_COMPILER "clang-cl")
    set(CMAKE_CXX_COMPILER "clang-cl")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
else ()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif ()

# Find libengine library
find_library(LIBENGINE_LIBRARY NAMES engine PATHS lib)

if (LIBENGINE_LIBRARY)
    message("libengine found: ${LIBENGINE_LIBRARY}")
else ()
    message(FATAL_ERROR "libengine not found. Please specify the correct path to libengine.")
endif ()

# Create demo_project executable
add_executable(demo_project main.cpp)

# Include libengine directories
target_include_directories(demo_project PRIVATE /path/to/libengine/include)

# Link libengine library
target_link_libraries(demo_project PRIVATE ${LIBENGINE_LIBRARY})
