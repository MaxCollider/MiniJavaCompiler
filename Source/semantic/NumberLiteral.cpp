#include "NumberLiteral.h"

NumberLiteral::NumberLiteral(int value): value_(value) {}

void NumberLiteral::Accept(Visitor* visitor) {
    visitor->Visit(this);
}