cmake_minimum_required(VERSION 2.8.6) # for CMakePushCheckState
project(drawbicyc CXX C)

find_package(HDF5 COMPONENTS CXX HL REQUIRED)
find_package(Boost COMPONENTS thread iostreams system timer program_options filesystem REQUIRED)

#find_package(Boost COMPONENTS filesystem REQUIRED)

set(CMAKE_CXX_FLAGS "-O3 -std=c++11")
add_subdirectory(plot_lgrngn)

