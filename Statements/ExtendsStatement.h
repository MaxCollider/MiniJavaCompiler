#pragma once

#include <string>

class ExtendsStatement {
  public:
    std::string title;
    ExtendsStatement(std::string name = "");
    std::string toString();
};