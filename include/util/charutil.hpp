#ifndef CHARUTIL_HPP
#define CHARUTIL_HPP

/*
 * utils used to recognize char type
 */
class CharUtils {
public:
    static bool isAlhpa(char c);
    static bool isDigit(char c);
    static bool isWhiteSpace(char c);
    static bool isDelimiter(char c);
    static bool isOperator(char c);
    static bool isBeginIdentifier(char c);
    static bool isPartIdentifier(char c);
    static bool isBeginNumber(char c);
    static bool isBeginString(char c);
    static bool isEndline(char c);
    static bool isSpace(char c);
};

#endif
