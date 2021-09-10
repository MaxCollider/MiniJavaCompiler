#pragma once

#include "Object.h"

class ObjectArray: public Object {
    public:
        ObjectArray(std::string type, int size);
        std::string type_;
        int size_;
        std::vector<Other> array;
        std::vector<Other>& GetArray() override;
        virtual std::string toString() override;
};