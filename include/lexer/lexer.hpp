#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>

#include "lexer/token.hpp"

/*
 * The lexer class is used to split a string into individual tokens.
 */
class Lexer {
public:
    Lexer();
    Lexer(std::string input);
    std::vector<Token> tokenize(std::string input);
    Token getNext();

private:
    std::string input;
    int pos;
    int line;
    int col;

    Token recognizeOperator();
    Token recognizeNumber();
    Token recognizeString();
    Token recognizeLiteral();
    Token recognizeDelimter();
};

#endif
