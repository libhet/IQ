cmake_minimum_required(VERSION 3.9)

enable_testing()
include(CTest)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

project(iq_test)

add_executable(${PROJECT_NAME}
        main_test.cpp
        random/lcg_test.cpp
        algorithms/sort_test.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        COMPILE_OPTIONS -std=c++11
        )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/tests)

target_link_libraries(${PROJECT_NAME} GTest::GTest Threads::Threads iq)

add_test(${PROJECT_NAME} ${PROJECT_NAME})