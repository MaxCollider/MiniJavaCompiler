#include <algorithm>
#include "AdditionOperator.h"

AdditionOperator::AdditionOperator(Expression * first, Expression * second): first(first), second(second) {}

void AdditionOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}