#ifndef VARNAME_HPP
#define VARNAME_HPP

#include <string>

#include "ast/expression.hpp"

class VarName : Expression {
public:
    VarName(std::string name);
    std::string getName();
private:
    std::string name;
};

#endif
