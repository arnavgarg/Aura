#include "lexer/token.hpp"

Token::Token(std::string value, TokenType type, int row, int col) : value(value), type(type), row(row), col(col) {}

std::string Token::getValue() {
    return value;
}

TokenType Token::getType() {
    return type;
}

int Token::getRow() {
    return row;
}

int Token::getCol() {
    return col;
}
