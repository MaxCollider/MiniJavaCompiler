#include "ExpressionStatement.h"

ExpressionStatement::ExpressionStatement(Expression * expr): _expr(expr) {}

void ExpressionStatement::Accept(Visitor* visitor) {
    visitor->Visit(this);
}