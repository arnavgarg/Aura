#
# CMakeLists for Aura Interpreter
#
project(Aura)
set(util_src
    charutil.cpp
    exception.cpp
)

set(EXECUTABLE_OUTPUT_PATH ../..)
add_executable(aura ${util_src})
target_link_libraries(aura lexer)
