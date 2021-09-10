#pragma once

#include "../Statements/Statement.h"
#include "Expression.h"

class PrintlnFunction: public Statement {
  public:
    Expression * expr_;
    PrintlnFunction(Expression * expr);
    virtual void Accept(Visitor* visitor);
};