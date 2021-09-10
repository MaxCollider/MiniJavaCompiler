#pragma once 

#include "../../Statements/Statement.h"
#include "Declaration.h"
#include <string>

class LocalVariableDeclaration: public Statement {
  public:
    Declaration * var_;
    LocalVariableDeclaration(Declaration * var);
    virtual void Accept(Visitor* visitor);
};