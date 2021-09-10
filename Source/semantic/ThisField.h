#pragma once

#include <string>
#include "Expression.h"

class ThisField: public Expression {
  public:
    std::string name_;
    ThisField(std::string name);
    virtual void Accept(Visitor* visitor);
};