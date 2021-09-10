#include "VariableReference.h"

VariableReference::VariableReference(std::string name): name_(std::move(name)) {}

void VariableReference::Accept(Visitor* visitor) {
    visitor->Visit(this);
}