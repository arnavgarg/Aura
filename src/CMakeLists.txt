#
# CMakeLists for Aura Interpreter
#
project(Aura)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(lexer)
add_subdirectory(util)
