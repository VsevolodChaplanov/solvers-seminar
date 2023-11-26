project(SLAESolversTests CXX)

file(GLOB SLAE_SOLVERS_TESTS_CXX_SOURCES ${CMAKE_CURRENT_LIST_DIR}/*pp)

message("SLAE_SOLVERS_TESTS_CXX_SOURCES ${SLAE_SOLVERS_TESTS_CXX_SOURCES}")

add_executable(${PROJECT_NAME} ${SLAE_SOLVERS_TESTS_CXX_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE
    Eigen3::Eigen
    boost::boost
    CFD::Solvers
    GTest::gtest
    GTest::gmock
)