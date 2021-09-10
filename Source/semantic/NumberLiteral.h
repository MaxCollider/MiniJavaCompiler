#pragma once

#include "Expression.h"

class NumberLiteral: public Expression {
  public:
    int value_;
    NumberLiteral(int value);
    virtual void Accept(Visitor* visitor) override;
};