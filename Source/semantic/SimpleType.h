#pragma once

#include <string>
#include "Type.h"

class SimpleType: public Type {
  public:
    std::string name_;
    SimpleType(std::string name);
    virtual std::string toString() override;
};