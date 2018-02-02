#include "lexer/lexer.hpp"
#include "lexer/fsm/fsm.hpp"
#include "util/charutil.hpp"
#include "util/exception.hpp"
#include <cstdio>

Lexer::Lexer() : pos(0), line(0), col(0) {}

std::vector<Token> Lexer::tokenize(std::string input) {
    this->input = input;
    std::vector<Token> tokens;

    Token token = getNext();
    while (token.getType() != EndOfInput) {
        if (token.getType() == Unrecognized) {
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

    if (CharUtil::isOperator(input[pos])) {
        return recognizeOperator();
    }

    if (CharUtil::isBeginNumber(input[pos])) {
        return recognizeNumber();
    }

    return Token("", Unrecognized, line, col);
}

Token Lexer::recognizeOperator() {
    char lookahead = pos + 1 < input.size() ? input[pos + 1] : '\0';
    switch (input[pos]) {
        case '+':
            pos++;
            col++;
            return Token("+", Add, line, col-1);
        case '-':
        pos++;
        col++;
            return Token("-", Sub, line, col-1);
        case '*':
            pos++;
            col++;
            return Token("*", Mul, line, col-1);
        case '/':
            pos++;
            col++;
            return Token("/", Div, line, col-1);
        case '%':
            pos++;
            col++;
            return Token("%", Mod, line, col-1);
        case '<':
            if (lookahead != '=') {
                pos++;
                col++;
                return Token("<", Less, line, col-1);
            } else {
                pos += 2;
                col += 2;
                return Token("<=", LessEqual, line, col-2);
            }
        case '>':
            if (lookahead != '=') {
                pos++;
                col++;
                return Token(">", Greater, line, col-1);
            } else {
                pos += 2;
                col += 2;
                return Token(">=", GreatEqual, line, col-2);
            }
        case '=':
            if (lookahead != '=') {
                pos++;
                col++;
                return Token("=", Equal, line, col-1);
            } else {
                pos += 2;
                col += 2;
                return Token("==", Assign, line, col-2);
            }
    }
    return Token(std::to_string(input[pos]), Unrecognized, line, col);
}

Token Lexer::recognizeNumber() {
    FSM fsm(std::set<int>{1,2,3}, 1, std::set<int> {2,3}, [](int state, char symbol) -> int {
        switch(state) {
            case 1:
                if (CharUtil::isDigit(symbol)) {
                    return 2;
                } else if (symbol == '.') {
                    return 3;
                }
                return FSM::INVALID_FSM_STATE;
            case 2:
                if (CharUtil::isDigit(symbol)) {
                    return 2;
                } else if (symbol == '.') {
                    return 3;
                }
                return FSM::INVALID_FSM_STATE;
            case 3:
                if (CharUtil::isDigit(symbol)) {
                    return 2;
                }
                return FSM::INVALID_FSM_STATE;
        }
        return FSM::INVALID_FSM_STATE;
    });
    std::tuple<bool, std::string> result = fsm.run(input.substr(pos));
    TokenType type = std::get<1>(result).find(".") != std::string::npos ? Double : Int;
    if (std::get<0>(result)) {
        return Token(std::get<1>(result), type, line, col);
    } else {
        return Token(std::get<1>(result), Unrecognized, line, col);
    }
}
