#include <exception>

class UnrecognizedTokenException : public std::exception {
public:
    UnrecognizedTokenException(int line, int col, char symbol);
    const char* what() const throw();
private:
    int line;
    int col;
    char symbol;
};

class UnclosedStringException : public std::exception {
public:
    const char* what() const throw();
};
