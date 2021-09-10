#pragma once

#include "semantic/Expression.h"

class OrOperator: public Expression {
  public:
    Expression * first, * second;
    OrOperator(Expression * first, Expression * second);
    virtual void Accept(Visitor* visitor) override;
};