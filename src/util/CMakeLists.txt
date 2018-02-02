#
# CMakeLists for Aura Interpreter
#
set(util_src
    charutil.cpp
    exception.cpp
)
add_executable(aura ${util_src})
target_link_libraries(aura lexer)
