#include "ClassStatement.h"

ClassStatement::ClassStatement(std::string name,
        ExtendsStatement * extends,
        Declarations * declarations
    ): _name(name), _extends(extends), _declarations(declarations) {}
  
void ClassStatement::Accept(Visitor* visitor) {
    visitor->Visit(this);
};