#pragma once

#include "semantic/Expression.h"
#include "semantic/Type.h"

class AllocateStatement: public Expression {
  public:
    Type * type;
    Expression * size;
    AllocateStatement(Type * type, Expression * size = 0);
    virtual void Accept(Visitor* visitor);
};