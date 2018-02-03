#include "lexer/token.hpp"

Token::Token(std::string value, TokenType type, int line, int col) : value(value), type(type), line(line), col(col) {}

std::string Token::getValue() {
    return value;
}

TokenType Token::getType() {
    return type;
}

int Token::getLine() {
    return line;
}

int Token::getCol() {
    return col;
}

std::string Token::toString() {
    return "<" + value + ", " + std::string(typeStrings[type-1]) + ", " + std::to_string(line) + ", " + std::to_string(col) + ">";
}
