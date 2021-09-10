#pragma once

#include "semantic/Expression.h"
#include "Statement.h"

class IfStatement: public Statement {
  public:
    Statement * _then;
    Expression * _cond;
    Statement * _if_else_;
    IfStatement (Expression * cond, Statement * then, Statement * ifelse = 0);
    virtual void Accept(Visitor* visitor);
};