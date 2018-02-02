#
# CMakeLists for Aura Interpreter
#
project(Aura)
set(lexer_src
    lexer.cpp
    token.cpp
    fsm/fsm.cpp
)
add_library(lexer ${lexer_src})
