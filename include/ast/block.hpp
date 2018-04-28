#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "ast/expression.hpp"

class Block : Expression {
public:
    Block();
    std::vector<Expression> getExpressions();
    void add(Expression expres);
private:
    std::vector<Expression> expressions;
};

#endif
