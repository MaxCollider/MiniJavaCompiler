#include "VariableDeclaration.h"

VariableDeclaration::VariableDeclaration(Type * type, std::string name): type_(type), name_(std::move(name)) {}

std::string VariableDeclaration::toString() { return type_->toString() + " " + name_; }

void VariableDeclaration::Accept(Visitor* visitor) {
    visitor->Visit(this);
};