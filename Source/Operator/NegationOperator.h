#pragma once

#include "semantic/Expression.h"

class NegationOperator: public Expression {
  public:
    Expression * expr_;
    NegationOperator(Expression * expr);
    virtual void Accept(Visitor* visitor);
};