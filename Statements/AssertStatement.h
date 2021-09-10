#pragma once

#include "Statement.h"
#include "semantic/Expression.h"

class AssertStatement: public Statement {
  public:
    Expression * _expr;
    AssertStatement(Expression * expr);
    virtual void Accept(Visitor* visitor);
};