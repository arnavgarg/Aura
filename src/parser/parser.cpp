#include "parser/parser.hpp"

Parser::Parser(std::string input) {
    lexer = Lexer(input);
}
