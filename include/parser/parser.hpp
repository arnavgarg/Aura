#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer/lexer.hpp"

class Parser {
public:
    Parser(std::string input);
    

private:
    Lexer lexer;
};

#endif
