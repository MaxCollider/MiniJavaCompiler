#pragma once

#include "Object.h"

class ObjectBool: public Object {
    public:
        bool value;
        ObjectBool(bool value);
        virtual int& GetInt();
        virtual bool& GetBool();
        virtual std::string toString();
};