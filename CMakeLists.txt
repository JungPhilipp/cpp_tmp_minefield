cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(examples VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)


#find_package(Catch2 REQUIRED)
#find_package(Eigen3 REQUIRED)


add_subdirectory(fold_expressions)
add_subdirectory(expression_templates)

