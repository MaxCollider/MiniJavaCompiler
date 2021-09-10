#include "SubtractionOperator.h"

SubtractionOperator::SubtractionOperator(Expression * first, Expression * second): first(first), second(second) {}

void SubtractionOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}