#pragma once

#include "Expression.h"

class BooleanLiteral: public Expression {
  public:
    bool value_;
    BooleanLiteral(bool value);
    virtual void Accept(Visitor* visitor);
};