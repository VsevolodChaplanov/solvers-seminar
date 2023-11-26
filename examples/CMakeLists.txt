project(CFDExamples CXX)

file(GLOB FULL_PATHS ${CMAKE_CURRENT_LIST_DIR}/*pp)
file(RELATIVE_PATH EXAMPLES_CXX_SOURCES ${CMAKE_CURRENT_LIST_DIR} ${FULL_PATHS})

foreach(EXAMPLE ${EXAMPLES_CXX_SOURCES})
    string(REPLACE ".cpp" "" EX_NAME ${EXAMPLE})
    add_executable(${EX_NAME} ${EXAMPLE})
    target_link_libraries(${EX_NAME} PRIVATE
        Eigen3::Eigen
        boost::boost
        CFD::Solvers
    )
endforeach()


