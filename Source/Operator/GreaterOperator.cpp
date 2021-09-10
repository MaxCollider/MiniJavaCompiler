#include "GreaterOperator.h"

GreaterOperator::GreaterOperator(Expression * first, Expression * second): first(first), second(second) {}

void GreaterOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}