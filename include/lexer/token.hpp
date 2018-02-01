#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

#include "lexer/tokentype.hpp"

class Token {
public:
    Token(std::string value, TokenType type, int line, int col);
    std::string getValue();
    TokenType getType();
    int getLine();
    int getCol();

private:
    std::string value;
    TokenType type;
    int line;
    int col;
};

#endif
