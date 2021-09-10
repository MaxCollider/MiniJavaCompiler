#pragma once

#include <string>
#include "semantic/Declarations.h"
#include "ExtendsStatement.h"

class ClassStatement: public Sample {
  public:
    std::string _name;
    ExtendsStatement * _extends;
    Declarations * _declarations;
    ClassStatement(std::string name,
        ExtendsStatement * extends,
        Declarations * declarations
    );
	virtual void Accept(Visitor*) override;
};