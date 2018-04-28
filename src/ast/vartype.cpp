#include "ast/vartype.hpp"
#include "util/exception.hpp"

VarType::VarType(TokenType ttype) {
    switch (ttype) {
        case IntDec:
            type = IntDecExpres;
            break;
        case DoubDec:
            type = DoubDecExpres;
            break;
        case BoolDecExpres:
            type = BoolDecExpres;
            break;
        case StrDecExpres:
            type = StrDecExpres;
            break;
        default:
            throw InvalidTypeException();
    }
}
