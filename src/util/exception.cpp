#include <string>

#include "util/exception.hpp"

UnrecognizedToken::UnrecognizedToken(int line, int col, char symbol) : line(line), col(col), symbol(symbol) {}

const char* UnrecognizedToken::what() const throw() {
    std::string msg = "Unrecognized Token at " + std::to_string(line) + ":" + std::to_string(col) + " ${" + std::string(&symbol) + "}";
    return msg.c_str();
}
