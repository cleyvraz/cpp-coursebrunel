cmake_minimum_required (VERSION 2.6)
project (Neuron)

set(CMAKE_CXX_FLAGS " -O3 -W -Wall -pedantic -std=c++11")

enable_testing()
add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Neuron main.cpp Neuron.cpp Network.cpp Generaterandom.cpp Generatepoisson.cpp)
add_executable(Neuron_unittest Neuron.cpp Generatepoisson.cpp Neuron_unittest.cpp)

target_link_libraries(Neuron_unittest gtest gtest_main)
add_test(Neuron_unittest Neuron_unittest)

