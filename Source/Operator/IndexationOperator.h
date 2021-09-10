#pragma once

#include "semantic/Expression.h"

class IndexationOperator: public Expression {
  public:
    Expression * obj_, * _index;
    IndexationOperator(Expression * obj, Expression * index);
    virtual void Accept(Visitor* visitor);
};