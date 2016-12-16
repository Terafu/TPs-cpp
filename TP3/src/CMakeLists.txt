################################################################################
# CMake for TP2 sources
#   Created on: Nov 19, 2011
#       Author: pesterie
################################################################################

include_directories(${PROJECT_SOURCE_DIR}/include/)
add_library(tp2 rectangle.cpp square.cpp)
