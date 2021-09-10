#include "NotOperator.h"

NotOperator::NotOperator(Expression * expr): expr_(expr) {}

void NotOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}