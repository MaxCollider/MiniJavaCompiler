#pragma once

#include "semantic/Expression.h"

class DivisionOperator: public Expression {
  public:
    Expression * first, * second;
    DivisionOperator(Expression * first, Expression * second);
    virtual void Accept(Visitor* visitor);
};