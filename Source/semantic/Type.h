#pragma once
#include <string>

class Type {
  public:
    virtual std::string toString() { return "Null"; };
    virtual ~Type() {};
};