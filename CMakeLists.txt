cmake_minimum_required(VERSION 3.22)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(find_max_sub_sequence 2/find_max_sub_sequence.cpp)

add_executable(Hoare_partition 7/Hoare_partition.cpp)

add_executable(main main.cpp)
target_sources(main PUBLIC "3/vector.h")
target_sources(main PUBLIC "3/List.h")