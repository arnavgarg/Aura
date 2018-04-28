#include "ast/block.hpp"

Block::Block() {
    type = BlockExpres;
}

std::vector<Expression> Block::getExpressions() {
    return expressions;
}

void Block::add(Expression expres) {
    expressions.push_back(expres);
}
