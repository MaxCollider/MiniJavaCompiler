#pragma once

#include "semantic/Expression.h"

class AndOperator: public Expression {
  public:
    Expression * first, * second;
    AndOperator(Expression * first, Expression * second);
    virtual void Accept(Visitor* visitor);
};