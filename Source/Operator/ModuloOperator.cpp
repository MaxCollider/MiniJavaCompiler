#include "ModuloOperator.h"

ModuloOperator::ModuloOperator(Expression * first, Expression * second): first(first), second(second) {}

void ModuloOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}