#include <exception>

class UnrecognizedToken : public std::exception {
public:
    UnrecognizedToken(int line, int col, char symbol);
    const char* what() const throw();
private:
    int line;
    int col;
    char symbol;
};
