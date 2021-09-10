#pragma once

#include "semantic/Expression.h"
#include "Statement.h"

class WhileStatement: public Statement {
  public:
    Expression * _cond;
    Statement * _then;
    WhileStatement(Expression * cond, Statement * then);
    virtual void Accept(Visitor* visitor);
};