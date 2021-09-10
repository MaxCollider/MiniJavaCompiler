#include "EqualityOperator.h"

EqualityOperator::EqualityOperator(Expression * first, Expression * second): first(first), second(second) {}

void EqualityOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}