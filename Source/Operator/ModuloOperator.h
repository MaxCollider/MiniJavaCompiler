#pragma once

#include "semantic/Expression.h"

class ModuloOperator: public Expression {
  public:
    Expression * first, * second;
    ModuloOperator(Expression * first, Expression * second);
    virtual void Accept(Visitor* visitor);
};