#include "AllocateStatement.h"

AllocateStatement::AllocateStatement(Type * type, Expression * size): type(type), size(size) {}

void AllocateStatement::Accept(Visitor* visitor) {
    visitor->Visit(this);
}