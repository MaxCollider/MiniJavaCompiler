#include "ThisField.h"


ThisField::ThisField(std::string name): name_(std::move(name)) {}

void ThisField::Accept(Visitor* visitor) {
    visitor->Visit(this);
}