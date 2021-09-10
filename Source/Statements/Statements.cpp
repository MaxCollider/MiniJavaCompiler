#include "Statements.h"

void Statements::Accept(Visitor* visitor) {
    visitor->Visit(this);
}