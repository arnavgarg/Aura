#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <vector>

#include "ast/expresstype.hpp"

class Expression {
public:
    ExpresType getType();
protected:
    ExpresType type;
};

#endif
