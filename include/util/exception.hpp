#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

/*
 * lexer found unrecognized token
 */
class UnrecognizedTokenException : public std::exception {
public:
    UnrecognizedTokenException(int line, int col, char symbol);
    const char* what() const throw();
private:
    int line;
    int col;
    char symbol;
};

/*
 * lexer started reading string but EOI reached before end of string
 */
class UnclosedStringException : public std::exception {
public:
    const char* what() const throw();
};

class InvalidTypeException : public std::exception {
public:
    const char* what() const throw();
};

#endif
