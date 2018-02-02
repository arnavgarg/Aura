#
# CMakeLists for Aura Interpreter
#
cmake_minimum_required(VERSION 3.1)
project(Aura)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)
file(GLOB_RECURSE src "src" "*.cpp")
add_executable(aura ${src})
