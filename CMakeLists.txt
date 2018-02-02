#
# CMakeLists for Aura Interpreter
#
cmake_minimum_required(VERSION 3.10)

project(Aura)
include_directories(include)
file(GLOB_RECURSE src "src" "*.cpp")
add_executable(aura ${src})
