#pragma once

#include "semantic/Expression.h"

class LengthOperator: public Expression {
  public:
    Expression * expr_;
    LengthOperator(Expression * expr);
    virtual void Accept(Visitor* visitor);
};