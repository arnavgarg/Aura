#include "ast/declaration.hpp"

Declaration::Declaration(VarType varType, VarName varName, Expression value) : varType(varType), varName(varName), value(value) {
    type = DecExpres;
}

VarType Declaration::getVarType() {
    return varType;
}

VarName Declaration::getVarName() {
    return varName;
}

Expression Declaration::getValue() {
    return value;
}
