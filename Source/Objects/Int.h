#pragma once

#include "Object.h"

class ObjectInt: public Object {
    public:
        int value;
        ObjectInt(int value);
        virtual int& GetInt();
        virtual std::string toString();
};