cmake_minimum_required(VERSION 3.18)
project(LL)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_library(catch2 INTERFACE)
target_include_directories(catch2 INTERFACE catch2/)

add_executable(LL
               main.cpp
               src/Common/Args.cpp
               src/Common/Args.h
               src/App/IModelProvider.h
               src/App/LLParser.cpp
               src/App/LLParser.h
               src/App/IInputReader.h
               src/Infrastructure/ModelProvider.cpp
               src/Infrastructure/ModelProvider.h
               src/Infrastructure/InputReader.cpp
               src/Infrastructure/InputReader.h)

add_subdirectory(tests)
