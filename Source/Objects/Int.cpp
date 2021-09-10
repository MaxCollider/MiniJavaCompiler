#include "Int.h"

ObjectInt::ObjectInt(int value): Object("int"), value(value) {}

int& ObjectInt::GetInt() {
    return value;
}
std::string ObjectInt::toString() {
    return std::to_string(value);
}