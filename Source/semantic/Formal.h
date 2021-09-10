#pragma once

#include <string>
#include "Type.h"

class Formal {
  private:
    Type * type_;
    std::string name_;
  public:
    Formal(Type * type, std::string name);
    std::string toString();
    std::string GetName();
};