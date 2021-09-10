#include "ArrayType.h"

ArrayType::ArrayType(std::string name): title(std::move(name)) {}

std::string ArrayType::toString() { return title + "[]"; }