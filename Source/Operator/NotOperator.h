#pragma once

#include "semantic/Expression.h"

class NotOperator: public Expression {
  public:
    Expression * expr_;
    NotOperator(Expression * expr);
    virtual void Accept(Visitor* visitor);
};