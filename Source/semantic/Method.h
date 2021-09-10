#pragma once

#include <string>
#include "Declaration.h"
#include "Type.h"
#include "Formals.h"
#include "../Statements/Statements.h"

class Method: public Declaration {
  public:
    std::string name_;
    Type * type_;
    Formals * formal_;
    Statements * statements_;

    Method(std::string name,
        Type * type,
        Formals * formals,
        Statements * statments
    );
    virtual void Accept(Visitor* visitor) override;
};