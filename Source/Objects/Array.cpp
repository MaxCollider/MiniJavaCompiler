#include "Array.h"
#include "Int.h"
#include "Boolean.h"

ObjectArray::ObjectArray(std::string type, int size): Object(type + "[" + std::to_string(size) + "]"), type_(type), size_(size) {
    array.resize(size);
    if (size != 0) {
        if (type == "int")
            for (auto& object: array)
                object = std::make_shared<ObjectInt>(0);
        else if (type == "boolean")
            for (auto& e: array)
                e = std::make_shared<ObjectBool>(false);
    }
}

std::vector<Other>& ObjectArray::GetArray() {
    return array;
}

std::string ObjectArray::toString() {
    std::string buff = "[";
    if (!array.empty()) {
        buff += array[0]->toString();
        for (size_t i = 1; i < array.size(); ++i)
            buff += std::string(", ") + array[i]->toString();
    }
    buff += "]";
    return buff;
}