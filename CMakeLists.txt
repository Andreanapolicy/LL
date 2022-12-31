cmake_minimum_required(VERSION 3.18)
project(LL)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(LL main.cpp)
