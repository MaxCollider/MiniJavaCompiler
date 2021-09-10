#pragma once

#include "Statement.h"
#include "semantic/Expression.h"

class ExpressionStatement: public Statement {
  public:
    Expression * _expr;
    ExpressionStatement(Expression * expr);
    virtual void Accept(Visitor* visitor);
};