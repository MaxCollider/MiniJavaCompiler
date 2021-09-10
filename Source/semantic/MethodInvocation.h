#pragma once

#include "Expression.h"
#include <string>
#include "Arguments.h"

class MethodInvocation: public Expression {
  public:
    Expression * expr_;
    std::string name_;
    Arguments * args_;
    MethodInvocation(
        Expression * expr,
        std::string name,
        Arguments * args
    );
    virtual void Accept(Visitor* visitor);
};