#include "IfStatement.h"

IfStatement::IfStatement(Expression * cond,
                         Statement * then,
                         Statement * ifelse
): _cond(cond), _then(then), _if_else_(ifelse) {}

void IfStatement::Accept(Visitor* visitor) {
    visitor->Visit(this);
}