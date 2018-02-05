#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

#include "lexer/tokentype.hpp"

/*
 * The token class holds the value, type, line#, and col# of a single token. 
 */
class Token {
public:
    Token(std::string value, TokenType type, int line, int col);
    std::string getValue();
    TokenType getType();
    int getLine();
    int getCol();
    std::string toString();

private:
    std::string value;
    TokenType type;
    int line;
    int col;
};

#endif
