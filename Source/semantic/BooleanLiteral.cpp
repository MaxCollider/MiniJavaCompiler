#include "BooleanLiteral.h"

BooleanLiteral::BooleanLiteral(bool value): value_(value) {}

void BooleanLiteral::Accept(Visitor* visitor) {
    visitor->Visit(this);
}