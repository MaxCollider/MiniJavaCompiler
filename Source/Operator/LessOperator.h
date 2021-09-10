#pragma once

#include "semantic/Expression.h"

class LessOperator: public Expression {
  public:
    Expression * first, * second;
    LessOperator(Expression * first, Expression * second);
    virtual void Accept(Visitor* visitor);
};