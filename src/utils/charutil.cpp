#include <string>

#include "utils/charutil.hpp"

bool CharUtil::isAlhpa(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool CharUtil::isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool CharUtil::isWhiteSpace(char c) {
    std::string str("\t\r\f\v\u00A0\u2028\u2029");
    return str.find(c) != std::string::npos;
}

bool CharUtil::isDelimiter(char c) {
    return c == ':' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == ';' || c == '\n';
}

bool CharUtil::isOperator(char c) {
    return c == '+' || c == '-' || c == '/' || c == '*' || c == '%' || c == '<' || c == '>' || c == '=';
}

bool CharUtil::isBeginIdentifier(char c) {
    return isAlhpa(c) || c == '_';
}

bool CharUtil::isPartIdentifier(char c) {
    return isAlhpa(c) || isDigit(c) || c == '_';
}

bool CharUtil::isBeginNumber(char c) {
    return isDigit(c) || c == '.';
}
