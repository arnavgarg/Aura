#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>

#include "lexer/token.hpp"

class Lexer {
public:
    Lexer();
    std::vector<Token> tokenize(std::string input);

private:
    std::string input;
    int pos;
    int line;
    int col;

    Token getNext();
    Token recognizeOperator();
    Token recognizeNumber();
    Token recognizeString();
};

#endif
