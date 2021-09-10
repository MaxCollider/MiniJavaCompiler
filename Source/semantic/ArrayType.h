#pragma once

#include "Type.h"
#include <string>

class ArrayType: public Type {
  public:
    ArrayType(std::string name_of_array);
    std::string title;
    virtual std::string toString() override;
};