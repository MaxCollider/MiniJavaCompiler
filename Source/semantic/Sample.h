#pragma once
#include <visitors/Visitor.h>

class Sample {
    public:
        virtual void Accept(Visitor *visitor) {};
        virtual ~Sample() {}
};