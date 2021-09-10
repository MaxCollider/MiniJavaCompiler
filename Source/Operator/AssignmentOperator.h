#pragma once

#include "semantic/Expression.h"
#include "../../Statements/Statement.h"

class AssignmentOperator: public Statement {
  public:
    Expression * dest_, * src_;
    AssignmentOperator(Expression * dst, Expression * src);
    virtual void Accept(Visitor* visitor);
};