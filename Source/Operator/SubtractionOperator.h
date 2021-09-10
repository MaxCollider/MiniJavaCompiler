#pragma once

#include "semantic/Expression.h"

class SubtractionOperator: public Expression {
  public:
    Expression * first, * second;
    SubtractionOperator(Expression * first, Expression * second);
    virtual void Accept(Visitor* visitor);
};