#include <string>

#include "util/exception.hpp"

UnrecognizedTokenException::UnrecognizedTokenException(int line, int col, char symbol) : line(line), col(col), symbol(symbol) {}

const char* UnrecognizedTokenException::what() const throw() {
    std::string msg = "Unrecognized Token at " + std::to_string(line) + ":" + std::to_string(col) + " ${" + std::string(&symbol) + "}";
    return msg.c_str();
}

const char* UnclosedStringException::what() const throw() {
    return "Unclosed String Exception";
}

const char* InvalidTypeException::what() const throw() {
    return "Invalid Type Exception";
}
