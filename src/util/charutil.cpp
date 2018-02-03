#include <string>

#include "util/charutil.hpp"

bool CharUtils::isAlhpa(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool CharUtils::isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool CharUtils::isWhiteSpace(char c) {
    std::string str("\t\r\f\v\u00A0\u2028\u2029");
    return str.find(c) != std::string::npos;
}

bool CharUtils::isDelimiter(char c) {
    return c == ':' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == ';' || c == '\n';
}

bool CharUtils::isOperator(char c) {
    return c == '+' || c == '-' || c == '/' || c == '*' || c == '%' || c == '<' || c == '>' || c == '=';
}

bool CharUtils::isBeginIdentifier(char c) {
    return isAlhpa(c) || c == '_';
}

bool CharUtils::isPartIdentifier(char c) {
    return isAlhpa(c) || isDigit(c) || c == '_';
}

bool CharUtils::isBeginNumber(char c) {
    return isDigit(c) || c == '.';
}

bool CharUtils::isBeginString(char c) {
    return c == '"';
}

bool CharUtils::isEndline(char c) {
    return c == '\n';
}
bool CharUtils::isSpace(char c) {
    return c == ' ';
}
