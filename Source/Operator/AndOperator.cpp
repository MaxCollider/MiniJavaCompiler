#include "AndOperator.h"

AndOperator::AndOperator(Expression * first, Expression * second): first(first), second(second) {}

void AndOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}