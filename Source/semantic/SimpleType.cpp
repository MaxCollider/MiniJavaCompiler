#include "SimpleType.h"

SimpleType::SimpleType(std::string name): name_(std::move(name)) {}

std::string SimpleType::toString() { return name_; }