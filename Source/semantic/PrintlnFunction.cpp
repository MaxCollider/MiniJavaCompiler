#include "PrintlnFunction.h"

PrintlnFunction::PrintlnFunction(Expression * expr): expr_(expr) {}

void PrintlnFunction::Accept(Visitor* visitor) {
    visitor->Visit(this);
}