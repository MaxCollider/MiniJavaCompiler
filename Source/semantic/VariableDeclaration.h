#pragma once

#include "Declaration.h"
#include <string>
#include "Type.h"

class VariableDeclaration: public Declaration {
  public:
    Type * type_;
    std::string name_;
    VariableDeclaration(Type * type, std::string name);
    std::string toString() override;
    virtual void Accept(Visitor* visitor) override;
};