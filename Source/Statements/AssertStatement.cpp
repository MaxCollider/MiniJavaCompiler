#include "AssertStatement.h"

AssertStatement::AssertStatement(Expression * expr): _expr(expr) {}

void AssertStatement::Accept(Visitor* visitor) {
    visitor->Visit(this);
}