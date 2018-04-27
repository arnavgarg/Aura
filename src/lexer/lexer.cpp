#include <iostream>
#include <map>

#include "lexer/lexer.hpp"
#include "lexer/fsm/fsm.hpp"
#include "util/charutil.hpp"
#include "util/exception.hpp"

Lexer::Lexer() : pos(0), line(1), col(0) {}

Lexer::Lexer(std::string input) : input(input), pos(0), line(1), col(0) {}

/*
 * splits the input string into a vector of tokens
 */
std::vector<Token> Lexer::tokenize(std::string input) {
    pos = 0; line = 1; col = 0;
    this->input = input;
    std::vector<Token> tokens;

    Token token = getNext();
    while (token.getType() != EndOfInput) {
        if (token.getType() == Unrecognized) {
            throw UnrecognizedTokenException(token.getLine(), token.getCol(), token.getValue()[0]);
        }

        tokens.push_back(token);
        token = getNext();
    }
    // push back EOI token
    tokens.push_back(token);

    return tokens;
}

Token Lexer::getNext() {
    if (pos >= input.size()) {
        return Token("EOI", EndOfInput, line, col);
    }

    if (CharUtils::isOperator(input[pos])) {
        return recognizeOperator();
    }

    if (CharUtils::isBeginNumber(input[pos])) {
        return recognizeNumber();
    }

    if (CharUtils::isBeginString(input[pos])) {
        return recognizeString();
    }

    if (CharUtils::isSpace(input[pos])) {
        pos++; col++;
        return Token(" ", Space, line, col-1);
    }

    if (CharUtils::isEndline(input[pos])) {
        int oldcol = col;
        pos++; col = 0; line++;
        return Token("\\n", Endline, line-1, oldcol);
    }

    if (CharUtils::isAlhpa(input[pos])) {
        return recognizeLiteral();
    }

    if (CharUtils::isDelimiter(input[pos])) {
        return recognizeDelimter();
    }

    return Token(std::to_string(input[pos]), Unrecognized, line, col);
}

Token Lexer::recognizeOperator() {
    // used to check if operator has 2 chars
    char lookahead = pos + 1 < input.size() ? input[pos + 1] : '\0';
    switch (input[pos]) {
        case '+':
            pos++; col++;
            return Token("+", Add, line, col-1);
        case '-':
            pos++; col++;
            return Token("-", Sub, line, col-1);
        case '*':
            pos++; col++;
            return Token("*", Mul, line, col-1);
        case '/':
            pos++; col++;
            return Token("/", Div, line, col-1);
        case '%':
            pos++; col++;
            return Token("%", Mod, line, col-1);
        case '<':
            if (lookahead != '=') {
                pos++; col++;
                return Token("<", Less, line, col-1);
            } else {
                pos += 2; col += 2;
                return Token("<=", LessEqual, line, col-2);
            }
        case '>':
            if (lookahead != '=') {
                pos++; col++;
                return Token(">", Greater, line, col-1);
            } else {
                pos += 2; col += 2;
                return Token(">=", GreatEqual, line, col-2);
            }
        case '=':
            if (lookahead != '=') {
                pos++; col++;
                return Token("=", Assign, line, col-1);
            } else {
                pos += 2; col += 2;
                return Token("==", Equal, line, col-2);
            }
    }
    return Token(std::to_string(input[pos]), Unrecognized, line, col);
}

Token Lexer::recognizeNumber() {
    FSM fsm(std::set<int>{1,2}, 1, std::set<int> {1,2}, [](int state, char symbol) -> int {
        switch(state) {
            case 1: // before decimal point is found
                if (CharUtils::isDigit(symbol)) {
                    return 1;
                } else if (symbol == '.') {
                    return 2;
                }
                return FSM::INVALID_FSM_STATE;
            case 2: // after decimal point is found
                if (CharUtils::isDigit(symbol)) {
                    return 2;
                }
                return FSM::INVALID_FSM_STATE;
        }
        return FSM::INVALID_FSM_STATE;
    });
    std::tuple<bool, std::string> result = fsm.run(input.substr(pos));
    // checks to see if decimal
    TokenType type = std::get<1>(result).find(".") != std::string::npos ? Double : Int;

    pos += std::get<1>(result).length();
    col += std::get<1>(result).length();

    if (std::get<0>(result)) {
        return Token(std::get<1>(result), type, line, col);
    } else {
        return Token(std::get<1>(result), Unrecognized, line, col);
    }
}

Token Lexer::recognizeString() {
    std::string buffer = input.substr(pos, 1); // gets "
    pos++; col++;

    while (input[pos] != '"') {
        buffer += input[pos];
        pos++; col++;
        if (CharUtils::isEndline(input[pos])) {
            line++;
        }
        if (pos >= input.size() && input[pos-1] != '"') {
            throw UnclosedStringException();
        }
    }
    buffer += input[pos];
    pos++; col++;

    return Token(buffer, String, line, col);
}

Token Lexer::recognizeLiteral() {
    std::string buffer = input.substr(pos, 1);
    pos++; col++;
    while(pos <= input.length() && CharUtils::isAlhpa(input[pos])) {
        buffer += input[pos];
        pos++; col++;
    }

    std::map<std::string, TokenType> keywords {
        { "if", If },
        { "else", Else},
        { "for", For },
        { "while", While },
        { "null", Null },
        { "func", Func },
        { "return", Return},
        { "true", Bool },
        { "false", Bool },
        { "int", IntDec },
        { "double", DoubDec },
        { "bool", BoolDec },
        { "string", StrDec }
    };
    // check to see if token is a keyword
    // if it is, return token of that type
    auto check = keywords.find(buffer);
    if (check != keywords.end()) {
        return Token(buffer, check->second, line, col-buffer.length());
    } else {
        return Token(buffer, Identifier, line, col-buffer.length());
    }
}

Token Lexer::recognizeDelimter() {
    pos++; col++;
    switch(input[pos-1]) {
        case ':':
            return Token(":", Colon, line, col-1);
        case '(':
            return Token("(", LeftParen, line, col-1);
        case ')':
            return Token(")", RightParen, line, col-1);
        case '{':
            return Token("{", LeftBrace, line, col-1);
        case '}':
            return Token("}", RightBrace, line, col-1);
        case '[':
            return Token("[", LeftBlock, line, col-1);
        case ']':
            return Token("]", RightBlock, line, col-1);
        case ';':
            return Token(";", Semicolon, line, col-1);
        case '\n':
            return Token("\\n", Endline, line, col-1);
    }
    return Token(std::string(&input[pos-1]), Unrecognized, line, col-1);
}
