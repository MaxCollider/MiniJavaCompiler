#include "IndexationOperator.h"

IndexationOperator::IndexationOperator(Expression * obj, Expression * index): obj_(obj), _index(index) {}

void IndexationOperator::Accept(Visitor* visitor) {
    visitor->Visit(this);
}