#include "OrOperator.h"

OrOperator::OrOperator(Expression * first, Expression * second): first(first), second(second) {}

void OrOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}