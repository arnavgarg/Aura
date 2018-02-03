#include <iostream>

#include "lexer/lexer.hpp"
#include "lexer/fsm/fsm.hpp"
#include "util/charutil.hpp"
#include "util/exception.hpp"

Lexer::Lexer() : pos(0), line(1), col(0) {}

int main() {
    Lexer lex;
    std::vector<Token> tokens = lex.tokenize("512.5 >= 32 * 098 \"test k\" \"hello\"\n\"Wow the code works!\"");
    for (Token token : tokens) {
        std::cout << token.toString() << std::endl;
    }
}

std::vector<Token> Lexer::tokenize(std::string input) {
    this->input = input;
    std::vector<Token> tokens;

    Token token = getNext();
    while (token.getType() != EndOfInput) {
        if (token.getType() == Unrecognized) {
            printf("%s\n", token.getValue().c_str());
            throw UnrecognizedToken(token.getLine(), token.getCol(), token.getValue()[0]);
        }
        tokens.push_back(token);
        token = getNext();
    }

    return tokens;
}

Token Lexer::getNext() {
    if (pos >= input.size()) {
        return Token("", EndOfInput, line, col);
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
        return Token(" ", Space, pos-1, col-1);
    }

    if (CharUtils::isEndline(input[pos])) {
        pos++; col++;
        return Token("\\n", Endline, pos-1, col-1);
    }

    printf("%s\n", &input[pos]);
    return Token(std::to_string(input[pos]), Unrecognized, line, col);
}

Token Lexer::recognizeOperator() {
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
                return Token("=", Equal, line, col-1);
            } else {
                pos += 2; col += 2;
                return Token("==", Assign, line, col-2);
            }
    }
    return Token(std::to_string(input[pos]), Unrecognized, line, col);
}
// TODO Simplify to 2 states
Token Lexer::recognizeNumber() {
    FSM fsm(std::set<int>{1,2,3}, 1, std::set<int> {2,3}, [](int state, char symbol) -> int {
        switch(state) {
            case 1:
                if (CharUtils::isDigit(symbol)) {
                    return 2;
                } else if (symbol == '.') {
                    return 3;
                }
                return FSM::INVALID_FSM_STATE;
            case 2:
                if (CharUtils::isDigit(symbol)) {
                    return 2;
                } else if (symbol == '.') {
                    return 3;
                }
                return FSM::INVALID_FSM_STATE;
            case 3:
                if (CharUtils::isDigit(symbol)) {
                    return 2;
                }
                return FSM::INVALID_FSM_STATE;
        }
        return FSM::INVALID_FSM_STATE;
    });
    std::tuple<bool, std::string> result = fsm.run(input.substr(pos));
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
    std::string buffer = input.substr(pos, 1);
    pos++; col++;

    while (input[pos] != '"') {
        buffer += input[pos];
        pos++; col++;
        if (CharUtils::isEndline(input[pos])) {
            line++;
        }
        if (pos >= input.size()) {
            // TODO throw exception
        }
    }
    buffer += input[pos];
    pos++; col++;

    return Token(buffer, String, line, col);
}
