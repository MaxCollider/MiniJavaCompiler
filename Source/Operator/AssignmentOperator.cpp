#include "AssignmentOperator.h"

AssignmentOperator::AssignmentOperator(Expression * dst, Expression * src): dest_(dst), src_(src) {}

void AssignmentOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}