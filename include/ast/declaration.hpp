#ifndef DECLARATION_HPP
#define DECLARATION_HPP

#include "ast/expression.hpp"
#include "ast/vartype.hpp"
#include "ast/varname.hpp"

class Declaration : Expression {
public:
    Declaration(VarType varType, VarName varName, Expression value);
    VarType getVarType();
    VarName getVarName();
    Expression getValue();
private:
    VarType varType;
    VarName varName;
    Expression value;
};

#endif
