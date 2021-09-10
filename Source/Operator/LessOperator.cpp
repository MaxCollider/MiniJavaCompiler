#include "LessOperator.h"

LessOperator::LessOperator(Expression * first, Expression * second): first(first), second(second) {}

void LessOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}