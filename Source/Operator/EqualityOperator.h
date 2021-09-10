#pragma once

#include "semantic/Expression.h"

class EqualityOperator: public Expression {
  public:
    Expression * first, * second;
    EqualityOperator(Expression * first, Expression * second);
    virtual void Accept(Visitor* visitor);
};