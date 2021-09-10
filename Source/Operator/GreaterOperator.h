#pragma once

#include "semantic/Expression.h"

class GreaterOperator: public Expression {
  public:
    Expression * first, * second;
    GreaterOperator(Expression * first, Expression * second);
    virtual void Accept(Visitor* visitor);
};