cmake_minimum_required(VERSION 3.20)

project(cpp-journey LANGUAGES CXX)

# Use C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find dependencies installed by vcpkg
find_package(fmt CONFIG REQUIRED)

# Automatically find all .cpp files under src/
#
# CONFIGURE_DEPENDS tells CMake to re-check the directory
# when new .cpp files are added or removed.
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

# Create the executable
add_executable(app ${SOURCES})

# Link third-party libraries
target_link_libraries(app PRIVATE
    fmt::fmt
)

# Compiler warnings for GCC and Clang
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(app PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()
