#pragma once

#include "semantic/Expression.h"

class MultiplicationOperator: public Expression {
  public:
    Expression * first, * second;
    MultiplicationOperator(Expression * first, Expression * second);
    virtual void Accept(Visitor* visitor);
};