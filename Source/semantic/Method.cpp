#include "Method.h"

Method::Method(std::string name,
        Type * type,
        Formals * formals,
        Statements * statments
    ): name_(std::move(name)), type_(type), formal_(formals), statements_(statments) {}

void Method::Accept(Visitor* visitor) {
    visitor->Visit(this);
}