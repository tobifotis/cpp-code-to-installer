# Minimum CMake version required
cmake_minimum_required(VERSION 3.15)

# Project name and language
project(compression-demo CXX)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)

# Find zlib (Conan generated the files that make this work)
find_package(ZLIB REQUIRED)

# Build an executable from our source files
add_executable(compression-demo src/main.cpp src/compressor.cpp)

# Link zlib to our executable
target_link_libraries(compression-demo ZLIB::ZLIB)