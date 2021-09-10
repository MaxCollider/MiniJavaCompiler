#pragma once

#include "Visitor.h"
#include "PrintVisitor.h"

template<typename T>
class TemplateVisitor : public Visitor {
 public:
   T Accept(Sample * element) {
      return value_;
   }
 protected:
    T value_ = T();
};