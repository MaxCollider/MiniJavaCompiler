#pragma once

#include "Expression.h"
#include <string>

class VariableReference: public Expression {
  public:
    std::string name_;
    VariableReference(std::string name);
    virtual void Accept(Visitor* visitor);
};