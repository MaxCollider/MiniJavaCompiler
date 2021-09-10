#include "MultiplicationOperator.h"

MultiplicationOperator::MultiplicationOperator(Expression * first, Expression * second): first(first), second(second) {}

void MultiplicationOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}