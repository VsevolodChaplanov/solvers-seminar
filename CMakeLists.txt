enable_testing()

# Require version
cmake_minimum_required(VERSION 3.25)

# Set project name
project(cfd-project CXX)

# Set CXX standard properties
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Set Ninja as default generator
set(CMAKE_GENERATOR Ninja)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Setting executables, libraries and artifacts output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(cmake/PopulateSYCL.cmake)

# Packages are provided by conan
find_package(Boost "1.82" REQUIRED)
find_package(Threads REQUIRED)
find_package(fmt "10" CONFIG REQUIRED)
find_package(GTest REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)

add_subdirectory(slae)
add_subdirectory(examples)