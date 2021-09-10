#pragma once

#include "Expression.h"

class ThisExpression: public Expression {
    public:
        virtual void Accept(Visitor* visitor) override;
};