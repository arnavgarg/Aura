#ifndef VARTYPE_HPP
#define VARTYPE_HPP

#include "ast/expression.hpp"
#include "lexer/tokentype.hpp"

class VarType : Expression {
public:
    VarType(TokenType type);
};

#endif
