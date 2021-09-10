#include <iostream>
#include "Object.h"

Object::Object(const std::string& class_name)
    : class_name(class_name) {}

int& Object::GetInt() {
    throw std::string("Can't convert '") + toString() + "' to 'int'.";
}
bool& Object::GetBool() {
    throw std::string("Can't convert '") + toString() + "' to 'boolean'.";
}
std::vector<Other>& Object::GetArray() {
    throw std::string("Can't convert '") + toString() + "' to 'Array'.";
}
std::string Object::toString() {
    return " ";
}
Method* Object::FindMethod(const std::string& method_name){
    auto it = methods.find(method_name);
    if (it == methods.end()) {
        return nullptr;
    }
    return it->second;
}

std::shared_ptr<Object> Object::FindField(const std::string& field_name) {
    auto it = fields.find(field_name);
    if (it == fields.end()) {
        return nullptr;
    }
    return it->second;
}

const std::string& Object::GetClassName() const {
    return class_name;
}