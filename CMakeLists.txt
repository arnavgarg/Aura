#
# CMakeLists for Aura Interpreter
#
cmake_minimum_required(VERSION 3.1)
project(Aura)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)
add_subdirectory(src)

set (run_src
    src/run.cpp
)

add_executable(aura ${run_src})
target_link_libraries(aura util)
