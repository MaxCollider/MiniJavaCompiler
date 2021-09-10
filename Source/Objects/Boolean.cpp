#include "Boolean.h"

ObjectBool::ObjectBool(bool value): Object("bool"), value(value) {}

int& ObjectBool::GetInt() {
    static int tmp = value;
    return tmp;
}
bool& ObjectBool::GetBool() {
    return value;
}
std::string ObjectBool::toString() {
    if (value){
        return "true";
    }
    else return "false";
}