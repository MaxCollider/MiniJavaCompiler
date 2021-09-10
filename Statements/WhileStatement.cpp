#include "WhileStatement.h"

WhileStatement::WhileStatement(Expression * cond,
                               Statement * then
): _cond(cond), _then(then) {}

void WhileStatement::Accept(Visitor* visitor) {
    visitor->Visit(this);
}