
cmake_minimum_required(VERSION 3.9)

project(iq)

set(SOURCES src/random/lcg.h
src/random/lcg.cpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES 
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON 
    COMPILE_OPTIONS -Wall -Wextra -Wpedantic
)

target_link_libraries(${PROJECT_NAME})

add_subdirectory(tests)