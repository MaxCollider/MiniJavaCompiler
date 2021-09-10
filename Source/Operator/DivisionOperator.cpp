#include "DivisionOperator.h"

DivisionOperator::DivisionOperator(Expression * first, Expression * second): first(first), second(second) {}

void DivisionOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}