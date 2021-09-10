#pragma once

#include <semantic/VariableDeclaration.h>
#include <semantic/Method.h>

struct ClassInformation{
    std::vector<VariableDeclaration*> fields;
    std::map<std::string, Method*> methods;
};