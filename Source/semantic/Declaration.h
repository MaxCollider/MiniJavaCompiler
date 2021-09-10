#pragma once
#include "Sample.h"
#include <string>

class Declaration: public Sample {
  public:
    virtual ~Declaration() {};
    virtual std::string toString() { return " "; };
};