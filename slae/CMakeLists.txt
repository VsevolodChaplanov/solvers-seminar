project(SLAESolvers CXX)

set(SLAE_SOVERS_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include/)
set(SLAE_SOVERS_SOURCES_DIR ${CMAKE_CURRENT_LIST_DIR}/src/)

file(GLOB_RECURSE SLAE_SOLVERS_CXX_HEADERS ${CMAKE_CURRENT_LIST_DIR}/include/*pp)
file(GLOB_RECURSE SLAE_SOLVERS_CXX_SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*pp)

add_library(${PROJECT_NAME} STATIC)
add_library(CFD::Solvers ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# TASK: add precompiled headers for solvers library and link it with it
# 
# * Name of the library must
#    - depend of project name
#    - have suffix pch
# * Automatically generate on configure phase
# * Generate independend OS code by generator expressions 
#   if required for project
#

message("SLAE_SOLVERS_CXX_HEADERS ${SLAE_SOLVERS_CXX_HEADERS}")

target_sources(${PROJECT_NAME} PRIVATE 
    ${SLAE_SOLVERS_CXX_HEADERS}
    ${SLAE_SOLVERS_CXX_SOURCES}    
)
target_include_directories(${PROJECT_NAME} PUBLIC 
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/>"
)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Eigen3::Eigen
    boost::boost
)

# TASK
# * make optional guard to build and run test 
# * define optional variable in cmake/Environment.cmake
#   to dis/allow buidling and running tests
add_subdirectory(tests)