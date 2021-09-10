#pragma once

#include "Collector.h"
#include "Statement.h"

class Statements: public Statement, public Collector<Statement*> {
    public:
        void Accept(Visitor* visitor) override;
};