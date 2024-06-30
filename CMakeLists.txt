cmake_minimum_required(VERSION 3.5)

# Project name
project(UseAfterMoveExamples)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)

# Add executables
add_executable(use_after_move use_after_move.cpp)
add_executable(use_after_move_example use_after_move_example.cpp)

# Enable compile commands output
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
