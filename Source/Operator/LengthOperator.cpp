#include "LengthOperator.h"

LengthOperator::LengthOperator(Expression * expr): expr_(expr) {}

void LengthOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}