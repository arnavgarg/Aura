#include "ast/varname.hpp"

VarName::VarName(std::string name) : name(name) {}

std::string VarName::getName() {
    return name;
}
