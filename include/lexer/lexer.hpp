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
    Token recognizeLiteral();
    Token recognizeDelimter();
};

#endif
