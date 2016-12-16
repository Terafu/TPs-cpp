################################################################################
# CMake for TP2
################################################################################
cmake_minimum_required(VERSION 2.8)

project(tp2-c++)

include_directories(${PROJECT_SOURCE_DIR}/include/)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/)
link_directories(${PROJECT_BINARY_DIR/src/})
add_executable(tp2.run main.cpp)
target_link_libraries(tp2.run tp2)

