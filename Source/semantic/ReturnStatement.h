#pragma once

#include "Expression.h"
#include "../Statements/Statement.h"

class ReturnStatement: public Statement {
  public:
    Expression * expr_;
    ReturnStatement(Expression * expr);
    virtual void Accept(Visitor* visitor);
};