#pragma once

#include "semantic/Expression.h"

class AdditionOperator: public Expression {
  public:
    Expression * first, * second;
    AdditionOperator(Expression * first, Expression * second);
    virtual void Accept(Visitor* visitor);
};