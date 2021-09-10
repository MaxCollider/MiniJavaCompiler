#pragma once

#include "Classes.h"
#include "Sample.h"

class Program: public Sample {
  public:
    Program(Classes * classes, ClassStatement* main);
    virtual void Accept(Visitor* visitor);
    Classes * classes_;
    ClassStatement * main_;
};