#include "NegationOperator.h"

NegationOperator::NegationOperator(Expression * expr): expr_(expr) {}

void NegationOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}